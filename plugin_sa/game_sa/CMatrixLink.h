#pragma once

// NOT FINISHED!

#include "plbase/PluginBase.h"
#include "CMatrix.h"
#include "CVector.h"

class PLUGIN_API CMatrixLink : public CMatrix
{
public:
	class CPlaceable  *m_pOwner;
	class CMatrixLink *m_pPrev;
	class CMatrixLink *m_pNext;

	CMatrixLink();
	~CMatrixLink();
	void Insert(CMatrixLink *matrixLink);
	void Remove();
};

VALIDATE_SIZE(CMatrixLink, 0x54);