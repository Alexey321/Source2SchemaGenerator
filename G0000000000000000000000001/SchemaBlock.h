#pragma once

#include "SchemaClassBinding.h"

typedef struct _SchemaBlock
{
	void* unknown1; // 0000
	struct _SchemaBlock* m_nextBlock; // 0008
	PSchemaClassBinding m_classBinding; // 0010
} SchemaBlock, *PSchemaBlock;





