#pragma once

#include <stdint.h>

typedef struct _SchemaClassBinding
{
	struct _SchemaClassBinding* m_pSchemaClassBindingFirst; // 0000
	PCHAR m_pClassName; // 0008
	PCHAR m_pDllName; // 0010
	PCHAR m_pLibraryName; // 0018
	int32_t m_nSizeof; // 0020
	int32_t m_nAlignof; // 0024
	int32_t nSomeInt1; // 0028
	int32_t nSomeInt2; // 002C
	void* m_pClassFieldsNamesArr; // 0030
	void* padding1; // 0038
	void* m_pSomeArr1; // 0040
	void* m_pSomeMetadataArr; // 0048
	PCSchemaSystemTypeScope m_pTypeScope; // 0050
	void* m_pUnknown1; // 0058
	int64_t m_nSomeSizeof; // 0060
	void* m_pUnknown2; // 0068
	// TODO
} SchemaClassBinding, *PSchemaClassBinding;