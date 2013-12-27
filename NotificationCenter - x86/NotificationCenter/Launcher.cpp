
#include "Launcher.h"

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new A2DFrame(xHInstance);
	aFrame->Initialize();

	mainPanel.Initialize();
	subPanel.Initialize();

	A2DToolkit::getSystemEventQueue(aFrame->id()).invokeLater(this); // To create the window!

	Sleep(5000);

	aFrame->SetVisible(false);

	Sleep(5000);

	aFrame->SetVisible(true);

	Sleep(5000);

	aFrame->dispose();
}

void Launcher::run(int xThreadId)
{
	// Force the random seeds to new
	// number.
	srand(xThreadId);

	aFrame->SetName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 0, 122, 204, 1.0f);
	aFrame->setShadow(0xFF, 0, 122, 204, 10.0f);
	aFrame->SetBounds(rand() % 800, rand() % 600, 800, 600);
	aFrame->SetVisible(true);

	SYSOUT_F("Event Dispatching Thread - x%X\n", xThreadId);

	A2DPanel& root = *aFrame->GetRootPane(); // Reference to make syntax easier
		
	mainPanel.SetBounds(30, 30, 100, 100);
	subPanel.SetBounds(130, 30, 100, 100);

	// root.SetOptBackgroundImage(&file3);
	mainPanel.SetOptBackgroundImage(&file4);
	subPanel.SetOptBackgroundImage(&file2);

	root.Add(&mainPanel);
	root.Add(&subPanel);

	root.SetDoubleBuffered(true);
	subPanel.blurred = true;
	mainPanel.blurred = true;
}