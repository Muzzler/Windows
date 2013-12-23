// NotificationCenter.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "NotificationCenter.h"

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);

	LPCTSTR file0 = L"Assets/images/muzzler windows-sync background [a] 1.jpg",
			file1 = L"Assets/images/muzzler windows-sync textureBackground [a] 4.jpg",
			file2 = L"Assets/images/muzzler windows-sync textureBackground [a] 5.jpg",
			file3 = L"Assets/images/muzzler windows-sync textureAlbumsWall [a] 1.jpg",
			file4 = L"Assets/images/muzzler windows-sync textureBackground [b] 1.png",
			title = L"Muzzler - Notification Center";

	HRESULT hr = S_OK;
	
	A2DFrame frame(xHInstance);

	hr = frame.Initialize();
	if (FAILED(hr))	return hr;
	
	frame.SetName(title);				// Set the title
	frame.SetBounds(0,0, 500, 500);		// Start at left corner
	frame.SetLocationRelativeTo(NULL);	// Center on screen

	A2DPanel& root = *frame.GetRootPane(); // Reference to make syntax easier

	root.SetOptBackgroundImage(&file0);
	
	frame.SetVisible(true);

	return hr;
}
