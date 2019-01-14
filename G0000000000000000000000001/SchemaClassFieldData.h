#pragma once

#include "SchemaStructures.h"

#include <stdint.h>

typedef struct _SchemaClassFieldData
{
	const char* m_Name; // 0000
	PSchemaType m_pSchemaType; // 0008
	int64_t m_nSingleInheritanceOffset; // 0010
	PSchemaMetadataSetData m_pMetadata; // 0018
} SchemaClassFieldData, *PSchemaClassFieldData;


