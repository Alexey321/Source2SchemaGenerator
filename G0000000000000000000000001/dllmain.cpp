// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

#include "Generate.h"
//#include "DllSelfUnload.h"


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:

		Generate();

		// doesn't work here
		//FreeModule(GetModuleHandle("G0000000000000000000000001.dll")); // NULL
		//DllSelfUnloading(hModule); // ( in the new thread )
		
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
		break;

    case DLL_PROCESS_DETACH:

		//MessageBox(NULL, "Completed !", "Source generator", MB_OK);

        break;
    }
    return TRUE;
}

