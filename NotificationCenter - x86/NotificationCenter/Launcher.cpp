
#include "Launcher.h"

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new A2DFrame(xHInstance);
	aFrame->Initialize();

	mainPanel.Initialize();
	subPanel.Initialize();

	A2DToolkit::getSystemEventQueue(aFrame->id()).invokeLater(this);
}

void Launcher::run()
{
	aFrame->SetName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 0, 122, 204, 1.0f);
	aFrame->setShadow(0xFF, 0, 122, 204, 10.0f);
	aFrame->SetLocationRelativeTo(NULL);
	aFrame->SetVisible(true);

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
	
	// No need to even call this!
	// aFrame->Update();
}