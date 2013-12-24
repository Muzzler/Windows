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
	frame->setBackground(0xF2, 0x34, 0x11);
	frame->setBorder(0xFF, 0xFF, 0xFF, 0xFF, 10.0f);
	frame->setShadow(0xFF, 0x00, 0xFF, 0x00, 100.0f);

	frame->SetSize(200, 200);		// Start at left corner
	frame->SetLocationRelativeTo(NULL);	// Center on screen
	
	std::thread dispatchThread(&startThread);

	A2DFrame frame2(xHInstance);

	hr = frame2.Initialize();
	if (FAILED(hr))	return hr;

	frame2.SetName(L"Muzzler - Notification Center");				// Set the title

	frame2.setBackground(0x00, 0x00, 0x00);
	frame2.setBorder(0xFF, 0xFF, 0xFF, 0xFF, 1.0f);
	frame2.setShadow(0xFF, 0x00, 0x00, 0x00, 50.0f);
	frame2.SetBounds(0, 0, 600, 500);		// Start at left corner	

	frame2.SetVisible(true);

	return hr;
}

void startThread()
{
	frame->SetVisible(true);
}
