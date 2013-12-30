
#include "Launcher.h"
#include <time.h>

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new Frame(xHInstance);
}

void Launcher::runOnEventDispatchingThread()
{
	aFrame->Initialize();

	Toolkit::getSystemEventQueue(aFrame->id())->invokeLater(this); // To create the window!
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

	Panel& root = *aFrame->GetRootPane(); // Reference to make syntax easier
		
	for (int cY = 0; cY < 1000; cY += 500)
	{
		for (int cX = 0; cX < 1000; cX += 400)
		{
			Panel * ap = new Panel();
			ap->Initialize();
			ap->SetBounds(cX, cY, 400, 400);
			ap->SetOptBackgroundImage(&file4);
			root.Add(ap);
		}
	}

	aFrame->SetVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}