
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
	LPCTSTR dvd1 = L"Assets/images/dvd1.jpg",
		dvd2 = L"Assets/images/dvd2.jpg",
		dvd3 = L"Assets/images/dvd3.jpg";

	RepaintManager& repaintManager = *aFrame->getRepaintManager();

	clock_t tStart = clock();

	srand(xThreadId);

	aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 0, 122, 204, 0.0f);
	aFrame->setShadow(0xFF, 0, 0, 0, 20.0f);
	aFrame->setBounds(0, 0, 800, 600);
	aFrame->setLocationRelativeTo(NULL);

	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		
	Paint salmon(0xffcc4d4d);
	Paint dark_black(0xFF11171c);
	Paint dark_black2(0xFF444444);

	Panel& panel = *new Panel;
	G_SAFELY(panel.initialize());
	panel.setSize(Styles::PERCENTAGE, 100, Styles::PERCENTAGE, 100);
	panel.setBackgroundPaint(Paint::WHITE);

	repaintManager.add(root, panel);

	Panel& sidebar = *new Panel;
	G_SAFELY(sidebar.initialize());
	sidebar.setSize(Styles::PERCENTAGE, 25, Styles::PERCENTAGE, 100);
	sidebar.setDisplay(Styles::INLINE_BLOCK);
	sidebar.setBackgroundPaint(dark_black);

	repaintManager.add(panel, sidebar);

	Panel& sidebar_top = *new Panel;
	G_SAFELY(sidebar_top.initialize());
	sidebar_top.setSize(Styles::PERCENTAGE, 100, Styles::PIXEL, 90);
	sidebar_top.setDisplay(Styles::INLINE_BLOCK);
	sidebar_top.setBackgroundPaint(salmon);

	repaintManager.add(sidebar, sidebar_top);

	Panel& main = *new Panel;
	G_SAFELY(main.initialize());
	main.setSize(Styles::PERCENTAGE, 75, Styles::PERCENTAGE, 100);
	main.setDisplay(Styles::INLINE_BLOCK);
	main.setBackgroundPaint(dark_black2);

	repaintManager.add(panel, main);

	Panel& item = *new Panel;
	G_SAFELY(item.initialize());
	item.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item.setPositioning(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item.setDisplay(Styles::INLINE_BLOCK);
	item.setBackgroundImage(dvd1);

	repaintManager.add(main, item);

	Panel& item2 = *new Panel;
	G_SAFELY(item2.initialize());
	item2.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item2.setPositioning(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item2.setDisplay(Styles::INLINE_BLOCK);
	item2.setBackgroundImage(dvd2);

	repaintManager.add(main, item2);

	Panel& item3 = *new Panel;
	G_SAFELY(item3.initialize());
	item3.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item3.setPositioning(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item3.setDisplay(Styles::INLINE_BLOCK);
	item3.setBackgroundImage(dvd3);

	repaintManager.add(main, item3);

	aFrame->setVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}