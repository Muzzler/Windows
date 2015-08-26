// NotificationCenter.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MainApplication.h"

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);

	LPCTSTR file0 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 3.jpg",
			file1 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 4.jpg",
			file2 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 5.jpg",
			file3 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureAlbumsWall [a] 1.jpg",
			file4 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [b] 1.png",
			title = L"Muzzler - Notification Center";

	HRESULT hr = S_OK;
	
	A2DFrame frame(&xHInstance);

	hr = frame.Initialize();
	if (FAILED(hr))	return hr;
	
	frame.SetName(&title);				// Set the title name
	frame.SetBounds(0,0, 500, 500);		// Start at left corner
	frame.SetLocationRelativeTo(NULL);	// Center on screen

	A2DPanel& root = *frame.GetRootPane(); // Reference to make syntax easier

	A2DPanel mainPanel;
	A2DPanel subPanel;

	hr = mainPanel.Initialize();
	if (FAILED(hr))	return hr;

	hr = subPanel.Initialize();
	if (FAILED(hr))	return hr;
	
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
