
#include "../../include/A2DGraphicsData.h"

A2DGraphicsData::A2DGraphicsData(){}

A2DGraphicsData::A2DGraphicsData(A2DGraphicsData * xRenderData){}

/////////////////////////////////////////////////////////////////////////////
// REQUIRED BY A2D_ABSTRACT
////////////////////////////////////////////////////////////////////////////

LPCWSTR A2DGraphicsData::GetClass()
{
	return L"A2DGraphicsData";
}

LPCWSTR A2DGraphicsData::ToString()
{
	return L"A2DGraphicsData";
}

bool A2DGraphicsData::operator==(A2DAbstract * xAbstract)
{
	return false;
}

HRESULT A2DGraphicsData::Initialize()
{
	return NULL;
}

void A2DGraphicsData::Deinitialize(){}