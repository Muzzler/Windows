// NotificationCenter.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Launcher.h"

A2DFrame * frame;

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);
	
	Launcher launcher(xHInstance);

	return A2DToolkit::waitForBackgroundThreads();
}