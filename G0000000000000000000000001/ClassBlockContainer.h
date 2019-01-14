#pragma once

#include "SchemaBlock.h"

typedef struct _ClassBlockContainer
{
	PSchemaBlock m_pSchemaBlock; // 0000
	void* padding1; // 0008
	void* padding2; // 0010
	void* padding3; // 0018
} ClassBlockContainer, *PClassBlockContainer;
