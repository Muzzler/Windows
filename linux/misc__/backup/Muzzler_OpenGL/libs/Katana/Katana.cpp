
#include "stdafx.h"
#include "globals.h"

Katana::Katana() :
kGraphics(NULL)
{
    kGraphics = new KatanaGraphics();
}

HRESULT Katana::Initialize()
{

    HRESULT hr;

    kGraphics = new KatanaGraphics();
    
    if(!kGraphics)
    {
		hr = E_FAIL;
    }
    
	return hr;
}

HRESULT Katana::SetSize(INT xWidth, INT xHeight)
{
    HRESULT hr = S_OK;

    if(aHwnd == NULL)
    {
        hr = E_FAIL;
    }
    else
    {
        //Resize
    }

    return hr;
}