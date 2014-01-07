
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
		netflix = L"Assets/images/netflix.jpg",
		dvd3 = L"Assets/images/dvd3.jpg";

	RepaintManager& repaintManager = *aFrame->getRepaintManager();

	clock_t tStart = clock();

	srand(xThreadId);

	aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 200, 200, 200, 10.0f);
	aFrame->setShadow(0xFF, 0, 0, 0, 10.0f);
	aFrame->setBounds(0, 0, 800, 600);
	aFrame->setLocationRelativeTo(NULL);

	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		
	Paint salmon(0xFFB9090B);
	Paint dark_black(0xFF11171c);
	Paint dark_black2(0xFF000000);
	Paint darkRed(0xFF8A0809);

	Panel& panel = *new Panel;
	G_SAFELY(panel.initialize());
	panel.setSize(Styles::PERCENTAGE, 100, Styles::PERCENTAGE, 100);
	panel.setBackgroundPaint(Paint::BLACK);

	repaintManager.add(root, panel);

	Panel& sidebar = *new Panel;
	G_SAFELY(sidebar.initialize());
	sidebar.setSize(Styles::PIXEL, 250, Styles::PERCENTAGE, 100);
	sidebar.setDisplay(Styles::INLINE_BLOCK);
	sidebar.setBackgroundPaint(dark_black);

	repaintManager.add(panel, sidebar);
	
	Panel& sidebar_top = *new Panel;
	G_SAFELY(sidebar_top.initialize());
	sidebar_top.setSize(Styles::PERCENTAGE, 100, Styles::PIXEL, 90);
	sidebar_top.setDisplay(Styles::INLINE_BLOCK);
	sidebar_top.setBackgroundImage(netflix);

	repaintManager.add(sidebar, sidebar_top);

	Panel& sidebar_right = *new Panel;
	G_SAFELY(sidebar_right.initialize());
	sidebar_right.setPosition(Styles::ABSOLUTE_);
	sidebar_right.setSize(Styles::PIXEL, 250, Styles::PERCENTAGE, 100);
	sidebar_right.setPositioning(Styles::PIXEL, Styles::AUTO, Styles::PIXEL, 0, Styles::PIXEL, 0, Styles::PIXEL, 0);
	sidebar_right.setDisplay(Styles::INLINE_BLOCK);
	sidebar_right.setBackgroundPaint(darkRed);

	repaintManager.add(panel, sidebar_right);
	
	Panel& main = *new Panel;
	G_SAFELY(main.initialize());
	main.setPosition(Styles::ABSOLUTE_);
	main.setPositioning(Styles::PIXEL, 250, Styles::PIXEL, 0, Styles::PIXEL, 250, Styles::PIXEL, 0);
	main.setSize(Styles::PIXEL, Styles::AUTO, Styles::PERCENTAGE, Styles::AUTO);
	main.setDisplay(Styles::INLINE_BLOCK);
	main.setBackgroundPaint(dark_black2);

	repaintManager.add(panel, main);
	
	Panel& item = *new Panel;
	G_SAFELY(item.initialize());
	item.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item.setDisplay(Styles::INLINE_BLOCK);
	item.setBackgroundImage(dvd1);

	repaintManager.add(main, item);

	Panel& item2 = *new Panel;
	G_SAFELY(item2.initialize());
	item2.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item2.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item2.setDisplay(Styles::INLINE_BLOCK);
	item2.setBackgroundImage(dvd2);

	repaintManager.add(main, item2);

	Panel& item3 = *new Panel;
	G_SAFELY(item3.initialize());
	item3.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item3.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item3.setDisplay(Styles::INLINE_BLOCK);
	item3.setBackgroundImage(dvd3);

	repaintManager.add(main, item3);

	Panel& item4 = *new Panel;
	G_SAFELY(item4.initialize());
	item4.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item4.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item4.setDisplay(Styles::INLINE_BLOCK);
	item4.setBackgroundImage(dvd1);

	repaintManager.add(main, item4);
	
	Panel& item5 = *new Panel;
	G_SAFELY(item5.initialize());
	item5.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item5.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item5.setDisplay(Styles::INLINE_BLOCK);
	item5.setBackgroundImage(dvd2);

	repaintManager.add(main, item5);
	
	Panel& item6 = *new Panel;
	G_SAFELY(item6.initialize());
	item6.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item6.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item6.setDisplay(Styles::INLINE_BLOCK);
	item6.setBackgroundImage(dvd3);

	repaintManager.add(main, item6);
	
	aFrame->setVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}