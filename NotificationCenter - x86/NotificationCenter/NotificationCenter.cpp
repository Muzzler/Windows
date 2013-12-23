// NotificationCenter.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "NotificationCenter.h"
#include <thread>

A2DFrame * frame;

void startThread();

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);

	HRESULT hr = S_OK;
	
	frame = new A2DFrame(xHInstance);

	hr = frame->Initialize();
	if (FAILED(hr))	return hr;
	
	frame->SetName(L"Muzzler - Notification Center");				// Set the title
	
	frame->SetSize(200, 200);		// Start at left corner
	frame->SetLocationRelativeTo(NULL);	// Center on screen
	
	std::thread dispatchThread(&startThread);

	A2DFrame frame2(xHInstance);

	hr = frame2.Initialize();
	if (FAILED(hr))	return hr;

	frame2.SetName(L"Muzzler - Notification Center");				// Set the title

	frame2.SetBounds(0, 0, 600, 500);		// Start at left corner	

	frame2.SetVisible(true);

	return hr;
}

void startThread()
{
	frame->SetVisible(true);
}
void startThread()
{
	frame->SetVisible(true);
}
