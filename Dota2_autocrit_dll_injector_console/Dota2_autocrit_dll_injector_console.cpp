// Dota2_autocrit_dll_injector_console.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>



#include "injector.h"




int main()
{

	Injector inj;
	inj.find_target_process("dota2.exe");


	//inj.inject("C:\\Users\\root\\source\\repos\\DumpMemoryTest0002\\x64\\Release\\DumpMemoryTest0002.dll");
	inj.inject("C:\\Users\\root\\source\\repos\\G0000000000000000000000001\\x64\\Debug\\G0000000000000000000000001.dll");
	//inj.inject("C:\\Users\\root\\source\\repos\\ttt_dotaHack\\Dota2_hook\\x64\\Release\\Dota2_hook.dll");
	//inj.inject("C:\\Users\\root\\source\\repos\\Dota2HookLogic_VAC_INSECURE\\Dota2HookLogic_VAC_INSECURE\\x64\\Release\\Dota2HookLogic_VAC_INSECURE.dll");
	
	//char buffer[MAX_PATH];
	//GetModuleFileName(NULL, buffer, MAX_PATH);
	//std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	//std::string path = std::string(buffer).substr(0, pos);
	//inj.inject(path + "\\Dota2_signature_test.dll");

	std::cout << "signature search test\n";
	std::cin.get();
}






















/*
#include <windows.h> 
#include <tlhelp32.h> 
#include <shlwapi.h> 
#include <conio.h> 
#include <stdio.h>
#include <iostream>
using namespace std;
#define WIN32_LEAN_AND_MEAN 
#define CREATE_THREAD_ACCESS (PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ)
DWORD GetProcessId(IN PCHAR szExeName)

{
	DWORD dwRet = 0;
	DWORD dwCount = 0;

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pe = { 0 };
		pe.dwSize = sizeof(PROCESSENTRY32);

		BOOL bRet = Process32First(hSnapshot, &pe);

		while (bRet)
		{
			if (!strcmp(szExeName, pe.szExeFile))
			{
				dwCount++;
				dwRet = pe.th32ProcessID;
			}
			bRet = Process32Next(hSnapshot, &pe);
		}

		if (dwCount > 1)
			dwRet = 0xFFFFFFFF;

		CloseHandle(hSnapshot);
	}

	return dwRet;
}

BOOL CreateRemoteThreadInject(DWORD ID, const char * dll)
{
	HANDLE Process;

	LPVOID Memory;

	LPVOID LoadLibrary;

	if (!ID) return false;

	Process = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, ID);

	LoadLibrary = (LPVOID)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryA");

	Memory = (LPVOID)VirtualAllocEx(Process, NULL, strlen(dll) + 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);

	WriteProcessMemory(Process, (LPVOID)Memory, dll, strlen(dll) + 1, NULL);

	CreateRemoteThread(Process, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibrary, (LPVOID)Memory, NULL, NULL);

	CloseHandle(Process);

	VirtualFreeEx(Process, (LPVOID)Memory, 0, MEM_RELEASE);

	return true;
}

int main()
{
	LPWSTR dll[MAX_PATH];

	GetFullPathName(L"Dota2_hook.dll", MAX_PATH, *dll, NULL);

	DWORD ID = GetProcessId("Xonix-Win64-Shipping.exe");

	char buffer[500];

	// First arg is the pointer to destination char, second arg is
	// the pointer to source wchar_t, last arg is the size of char buffer
	wcstombs(buffer, *dll, 500);

	if (!CreateRemoteThreadInject(ID, buffer)) cout << "failure";

	else cout << "success";

	return 0;
}
*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
