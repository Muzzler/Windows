#include "../../include/A2DExtLibs.h"
#include "../../include/A2DCPWindowHandle.h"

A2DCPWindowHandle::A2DCPWindowHandle(){}

A2DCPWindowHandle::~A2DCPWindowHandle(){}

#ifndef WIN32
Window A2DCPWindowHandle::getWindowHandle()
{
	return aHandle;
}

void A2DCPWindowHandle::setWindowHandle(Window xHandle)
{
	aHandle = xHandle;
}
#else
HWND A2DCPWindowHandle::getWindowHandle()
{
	return aHandle;
}
void A2DCPWindowHandle::setWindowHandle(HWND xHandle)
{
	aHandle = xHandle;
}
#endif