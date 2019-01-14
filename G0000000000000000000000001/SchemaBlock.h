#pragma once

#include "SchemaClassBinding.h"

typedef struct _SchemaBlock
{
	void* unknown1; // 0000
	struct _SchemaBlock* m_pNextBlock; // 0008
	PSchemaClassBinding m_pClassBinding; // 0010
} SchemaBlock, *PSchemaBlock;





