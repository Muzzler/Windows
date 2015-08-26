#include "../../include/K2DExtLibs.h"
#include "../../include/K2DAbstract.h"

K2DAbstract::K2DAbstract(){}

K2DAbstract::~K2DAbstract(){}

string K2DAbstract::GetClass()
{
    return "K2DAbstract";
}

string K2DAbstract::ToString()
{
    return "K2DAbstract";
}

bool K2DAbstract::operator==(K2DAbstract * xAbstract)
{
    return this == xAbstract;
}

bool A2DAbstract::isClass(LPCWSTR xClass)
{
    return wcscmp(GetClass(), xClass) == 0;
}