
#include "Launcher.h"
#include <time.h>

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new A2DFrame(xHInstance);
}

void Launcher::runOnEventDispatchingThread()
{
	aFrame->Initialize();

	A2DToolkit::getSystemEventQueue(aFrame->id())->invokeLater(this); // To create the window!
}

void Launcher::run(int xThreadId)
{
	clock_t tStart = clock();

	srand(xThreadId);

	aFrame->SetName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 0, 122, 204, 1.0f);
	aFrame->setShadow(0xFF, 0, 122, 204, 10.0f);
	aFrame->SetBounds(0, 0, 800, 600);
	aFrame->SetLocationRelativeTo(NULL);

	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	A2DPanel& root = *aFrame->GetRootPane(); // Reference to make syntax easier
		
	int cX = 10;
	int cY = 10;

	for (int cY = 10; cY < 1000; cY += 247)
	{
		for (cX = 10; cX < 1000; cX += 247)
		{
			A2DPanel * ap = new A2DPanel();
			ap->Initialize();
			ap->SetBounds(cX, cY, 237, 237);
			ap->SetOptBackgroundImage(&file4);
			root.Add(ap);
		}
	}

	aFrame->SetVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}