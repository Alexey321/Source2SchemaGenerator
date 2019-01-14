#pragma once

#include "ClassBlockContainer.h"
#include "SchemaBlock.h"
#include "SchemaClassBinding.h"


typedef void* PCSchemaSystem;
typedef void* PCSchemaSystemTypeScope;


typedef PCSchemaSystem(*CreateInterfaceFn)(const char*, int*);


#define GlobalTypeScopeIndex 11

typedef PCSchemaSystemTypeScope(__fastcall* GlobalTypeScopeFn)(PCSchemaSystemTypeScope pCSchemaSystemTypeScope/*this*/);

PCSchemaSystem g_pSchemaSystem;

#define ClassesDefinitionsStartOffset 0x618
#define EnumsDefinitionsStartOffset 0x2660

//typedef void* PClassBlockContainer; // defined in ClassBlockContainer.h
typedef void* PEnumDefinitionBlock;

// TODO: reclass SchemaBlock, EnumDefinitionBlock, CSchemaSystemTypeScope