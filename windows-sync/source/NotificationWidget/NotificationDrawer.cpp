// NotificationDrawer.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "NotificationDrawer.h"

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);

	LPCTSTR file0 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 3.jpg",
			file1 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 4.jpg",
			file2 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 5.jpg",
			file3 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureAlbumsWall [a] 1.jpg",
			file4 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [b] 1.png",
			title = L"Test Application";

	HRESULT hr = S_OK;

	A2DFrame frame;	
	hr = frame.Initialize();
	if (!hr)	return hr;
	
	frame.SetName(&title);				// Set the title
	frame.SetBounds(0,0, 500, 500);		// Start at left corner
	frame.SetLocationRelativeTo(NULL);	// Center on screen

	A2DPanel& root = *frame.GetRootPane(); // Reference to make syntax easier
	
	A2DPanel mainPanel;
	mainPanel.Initialize();
	if (!hr)	return hr;

	A2DPanel subPanel;
	subPanel.Initialize();
	if (!hr)	return hr;
	
	mainPanel.SetBounds(0, 0, 300, 300);
	subPanel.SetBounds(0, 0, 200, 700);

	root.SetOptBackgroundImage(&file3);
	mainPanel.SetOptBackgroundImage(&file4);
	subPanel.SetOptBackgroundImage(&file4);
	
	root.Add(&mainPanel);
	root.Add(&subPanel);

	root.SetDoubleBuffered(true);
	subPanel.blurred = true;
	mainPanel.blurred = true;
	
	frame.SetVisible(true);

	return hr;
}
