#pragma once

#include <Windows.h>
#include <tchar.h>  
#include <process.h>

typedef BOOL(WINAPI *PFreeLibrary)(_In_ HMODULE hModule);
typedef VOID(WINAPI *PExitThread)(_In_ DWORD dwExitCode);
typedef unsigned int (WINAPI *PTHREADPROC)(LPVOID lParam);

typedef struct _DLLUNLOADINFO
{
	PFreeLibrary	m_fpFreeLibrary;
	PExitThread		m_fpExitThread;
	HMODULE		    m_hFreeModule;
} DLLUNLOADINFO, *PDLLUNLOADINFO;

unsigned int WINAPI DllUnloadThreadProc(LPVOID lParam)
{
	PDLLUNLOADINFO pDllUnloadInfo = (PDLLUNLOADINFO)lParam;
	(pDllUnloadInfo->m_fpFreeLibrary)(pDllUnloadInfo->m_hFreeModule);
	pDllUnloadInfo->m_fpExitThread(0);
	return 0;
}

VOID DllSelfUnloading(_In_ const HMODULE hModule)
{
	PVOID pMemory = NULL;
	ULONG_PTR ulFuncSize;
	unsigned int uintThreadId = 0;

	pMemory = VirtualAlloc(NULL, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (pMemory != NULL)
	{
		ulFuncSize = (ULONG_PTR)DllUnloadThreadProc - (ULONG_PTR)DllSelfUnloading;
		if ((ulFuncSize >> 31) & 0x01)
		{
			ulFuncSize = (ULONG_PTR)DllSelfUnloading - (ULONG_PTR)DllUnloadThreadProc;
		}

		memcpy(pMemory, DllUnloadThreadProc, ulFuncSize);

		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_fpFreeLibrary =
			(PFreeLibrary)GetProcAddress(GetModuleHandle("kernel32.dll"), "FreeLibrary");

		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_fpExitThread =
			(PExitThread)GetProcAddress(GetModuleHandle("kernel32.dll"), "ExitThread");

		((PDLLUNLOADINFO)(((ULONG_PTR)pMemory) + 0x500))->m_hFreeModule = hModule;

		_beginthreadex(NULL, 0, (PTHREADPROC)pMemory, (PVOID)(((ULONG_PTR)pMemory) + 0x500), 0, &uintThreadId);
	}
}