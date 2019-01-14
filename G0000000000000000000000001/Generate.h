#pragma once

#include "SchemaStructures.h"

#include <Windows.h>

#include <fstream>
#include <string>


using namespace std;

#define GEN_FOLDER string("D:\\Source2GenOutput")






PCSchemaSystem GetSchemaSystem(const char* dllName, const char* fullName)
{
	PCSchemaSystem pCSchemaSystem = NULL;

	HMODULE dll = nullptr;

	do
	{
		dll = GetModuleHandle(dllName);
	} 
	while (!dll);

	CreateInterfaceFn pCreateInterface = (CreateInterfaceFn)GetProcAddress(dll, "CreateInterface");
	pCSchemaSystem = (PCSchemaSystem)(pCreateInterface(fullName, nullptr));
	return pCSchemaSystem;
}

void Generate()
{
	ofstream log(GEN_FOLDER + "\\" + "log.txt", ofstream::out | ofstream::app);
	log << "Start generating\n";

	log << "\tTrying to aquire CSchemaSystem*\n";
	g_pSchemaSystem = GetSchemaSystem("schemasystem.dll", "SchemaSystem_001");
	if (g_pSchemaSystem)
	{
		log << "\t\tFound CSchemaSystem* at addr " << std::hex << g_pSchemaSystem << "\n";

		log << "\tTrying to aquire GlobalTypeScopeFn at addr " << std::hex << (void*)((*(UINT_PTR**)g_pSchemaSystem)[GlobalTypeScopeIndex]) << "\n\t(vtable addr " << std::hex << g_pSchemaSystem << " offset to function " << std::hex << (GlobalTypeScopeIndex * 8) << "\n";
		GlobalTypeScopeFn pGlobalTypeScopeFn = (GlobalTypeScopeFn)((void*)((*(UINT_PTR**)g_pSchemaSystem)[GlobalTypeScopeIndex]));

		if (pGlobalTypeScopeFn)
		{
			log << "\t\tFound GlobalTypeScopeFn at addr " << std::hex << pGlobalTypeScopeFn << "\n";

			log << "\tTrying to aquire PCSchemaSystemTypeScope\n";
			PCSchemaSystemTypeScope pCSchemaSystemTypeScope = pGlobalTypeScopeFn(g_pSchemaSystem);

			if (pCSchemaSystemTypeScope)
			{
				log << "\t\tFound PCSchemaSystemTypeScope at addr " << std::hex << pCSchemaSystemTypeScope << "\n";

				log << "\tTrying to aquire ClassDefinitionFirstBlock* (PCSchemaSystemTypeScope* + ClassesDefinitionsStartOffset)\n\t" << std::hex << pCSchemaSystemTypeScope << " + " << std::hex << ClassesDefinitionsStartOffset << " = " << std::hex << (void*)((char*)pCSchemaSystemTypeScope + ClassesDefinitionsStartOffset) << "\n";
				PClassBlockContainer pClassDefinitionFirstBlock = (PClassBlockContainer)((char*)pCSchemaSystemTypeScope + ClassesDefinitionsStartOffset);
				if (pClassDefinitionFirstBlock)
				{
					log << "\t\tFound ClassDefinitionFirstBlock* at addr " << std::hex << pClassDefinitionFirstBlock << "\n";

					log << "\tTrying to aquire EnumDefinitionFirstBlock* (PCSchemaSystemTypeScope* + EnumsDefinitionsStartOffset)\n\t" << std::hex << pCSchemaSystemTypeScope << " + " << std::hex << EnumsDefinitionsStartOffset << " = " << std::hex << (void*)((char*)pCSchemaSystemTypeScope + EnumsDefinitionsStartOffset) << "\n";
					PEnumDefinitionBlock pEnumDefinitionFirstBlock = (void*)((char*)pCSchemaSystemTypeScope + EnumsDefinitionsStartOffset);
					if (pClassDefinitionFirstBlock)
					{
						log << "\t\tFound EnumDefinitionFirstBlock* at addr " << std::hex << pEnumDefinitionFirstBlock << "\n";



					}
					else
					{
						log << "\t\tFailed to aquire EnumDefinitionFirstBlock*\n";
						goto LBL_END_GENERATING;
					}
				}
				else
				{
					log << "\t\tFailed to aquire ClassDefinitionFirstBlock*\n";
					goto LBL_END_GENERATING;
				}

			}
			else
			{
				log << "\tFailed to aquire PCSchemaSystemTypeScope\n";
				goto LBL_END_GENERATING;
			}
		}
		else
		{
			log << "\t\tFailed to aquire GlobalTypeScopeFn\n";
			goto LBL_END_GENERATING;
		}
	}
	else
	{
		log << "\t\tFailed to aquire CSchemaSystem*\n";
		goto LBL_END_GENERATING;
	}

LBL_END_GENERATING:
	log << "End generating\r\n";

}

