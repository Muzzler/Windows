
#include "Launcher.h"
#include "CustomPanel.h"

#include <time.h>

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new Frame(xHInstance);
}

void Launcher::runOnEventDispatchingThread()
{
	G_SAFELY(aFrame->initialize());
	
	Toolkit::getSystemEventQueue(aFrame->id())->invokeLater(this); // To create the window!
}

void Launcher::run(int xThreadId)
{
	RepaintManager& repaintManager = *aFrame->getRepaintManager();

	clock_t tStart = clock();

	srand(xThreadId);

	aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 0, 122, 204, 1.0f);
	aFrame->setShadow(0xFF, 0, 122, 204, 10.0f);
	aFrame->setBounds(0, 0, 800, 600);
	aFrame->setLocationRelativeTo(NULL);

	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		
	Panel& panel = *new Panel;
	G_SAFELY(panel.initialize());
	panel.setSize(Styles::PERCENTAGE, 100, Styles::PERCENTAGE, 100);
	panel.setBackgroundPaint(Paint::MIDNIGHT_BLUE);

	repaintManager.add(root, panel);

	Panel& header = *new Panel;
	G_SAFELY(header.initialize());
	header.setSize(Styles::PERCENTAGE, 100, Styles::PIXEL, 100);
	header.setDisplay(Styles::BLOCK);
	header.setBackgroundPaint(Paint::WET_ASPHALT);

	repaintManager.add(panel, header);

	Panel& half1 = *new Panel;
	G_SAFELY(half1.initialize());
	half1.setSize(Styles::PERCENTAGE, 50, Styles::PIXEL, 50);
	half1.setDisplay(Styles::INLINE_BLOCK);
	half1.setBackgroundPaint(Paint::ALIZARIN);

	repaintManager.add(header, half1);
	
	Panel& half2 = *new Panel;
	G_SAFELY(half2.initialize());
	half2.setSize(Styles::PERCENTAGE, 50, Styles::PIXEL, 50);
	half2.setDisplay(Styles::INLINE_BLOCK);
	half2.setBackgroundPaint(Paint::NEPHRITIS);

	repaintManager.add(header, half2);

	aFrame->setVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}