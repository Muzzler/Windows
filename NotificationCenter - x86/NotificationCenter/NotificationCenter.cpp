// NotificationCenter.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Launcher.h"

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);
		
	Launcher launcher(xHInstance);

	launcher.runOnEventDispatchingThread();

	return Toolkit::waitForBackgroundThreads();
}