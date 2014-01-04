
#include "Launcher.h"

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new A2DFrame(xHInstance);

	mainPanel.Initialize();
	subPanel.Initialize();
	
	// Sleep(5000);

	//  aFrame->SetVisible(false);

	//  Sleep(5000);

	// aFrame->SetVisible(true);

	// Sleep(5000);

	// aFrame->dispose();
}

// Note: This feature is not allowed due to convoluted
// code that needs happen to make this work. In fact,
// this feature is quite useless.
//
//void launcher::runonmainthread()
//{
//	aframe->initialize_();
//
//	run(0);
//}

void Launcher::runOnEventDispatchingThread()
{
	aFrame->Initialize();

	A2DToolkit::getSystemEventQueue(aFrame->id())->invokeLater(this); // To create the window!
}

void Launcher::run(int xThreadId)
{
	// Force the random seeds to new
	// number.
	srand(xThreadId);

	aFrame->SetName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 0, 122, 204, 1.0f);
	aFrame->setShadow(0xFF, 0, 122, 204, 50.0f);
	aFrame->SetBounds(rand() % 800, rand() % 600, 800, 600);
	aFrame->getWindow()->addMouseListener(new A2DMouseListener());
	aFrame->getWindow()->addMouseMotionListener(new A2DMouseMotionListener());


	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	A2DPanel& root = *aFrame->GetRootPane(); // Reference to make syntax easier
	mainPanel.SetBounds(30, 30, 100, 100);
	subPanel.SetBounds(130, 30, 100, 100);
	
	// root.SetOptBackgroundImage(&file3);
	mainPanel.SetOptBackgroundImage(&file4);
	subPanel.SetOptBackgroundImage(&file2);

	root.Add(&mainPanel);
	root.Add(&subPanel);

	mainPanel.addMouseMotionListener(new A2DMouseMotionListener());
	subPanel.addMouseMotionListener(new A2DMouseMotionListener());

	root.SetDoubleBuffered(true);
	subPanel.blurred = true;
	mainPanel.blurred = true;

	aFrame->SetVisible(true);
}