// NotificationCenter.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "NotificationCenter.h"

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);

	HRESULT hr = S_OK;
	
	A2DFrame frame(xHInstance);

	hr = frame.Initialize();
	if (FAILED(hr))	return hr;
	
	frame.SetName(L"Muzzler - Notification Center");				// Set the title
	
	frame.SetBounds(0,0, 600, 500);		// Start at left corner
	frame.SetLocationRelativeTo(NULL);	// Center on screen
	
	frame.SetVisible(true);

	return hr;
}
