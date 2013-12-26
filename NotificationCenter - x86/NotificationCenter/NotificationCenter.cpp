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

	LPCTSTR file0 = L"Assets/images/free [a] 1.jpg",
			file1 = L"Assets/images/muzzler windows-sync textureBackground [a] 1.jpg",
			file2 = L"Assets/images/muzzler windows-sync background [a] 1.jpg",
			file3 = L"Assets/images/muzzler windows-sync textureBackground [a] 1.jpg",
			file4 = L"Assets/images/muzzler windows-sync textureBackground [a] 2.jpg",
			title = L"Muzzler - Notification Center";

	HRESULT hr = S_OK;
	
	frame = new A2DFrame(xHInstance);

	hr = frame->Initialize();
	if (FAILED(hr))        return hr;

	frame->SetName(L"Muzzler - Notification Center");                                // Set the title
	frame->setBackground(0xF2, 0x34, 0x11);
	frame->setBorder(0xFF, 0xFF, 0xFF, 0xFF, 10.0f);
	frame->setShadow(0xFF, 0x00, 0xFF, 0x00, 100.0f);

	frame->SetLocationRelativeTo(NULL);        // Center on screen

	A2DPanel& root = *frame->GetRootPane(); // Reference to make syntax easier

	A2DPanel mainPanel;
	A2DPanel subPanel;

	hr = mainPanel.Initialize();
	if (FAILED(hr))        return hr;

	hr = subPanel.Initialize();
	if (FAILED(hr))        return hr;

	mainPanel.SetBounds(0, 0, 600, 700);
	subPanel.SetBounds(50, 0, 600, 600);

	root.SetOptBackgroundImage(&file3);
	mainPanel.SetOptBackgroundImage(&file4);
	subPanel.SetOptBackgroundImage(&file2);

	root.Add(&mainPanel);
	root.Add(&subPanel);

	root.SetDoubleBuffered(true);
	subPanel.blurred = true;
	mainPanel.blurred = true;

	frame->SetVisible(true);

	return hr;
}
void startThread()
{
	frame->SetVisible(true);
}
