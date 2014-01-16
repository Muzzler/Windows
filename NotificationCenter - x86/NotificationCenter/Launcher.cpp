
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
		dvd3 = L"Assets/images/dvd3.jpg",
		sample = L"Assets/images/texture_sample.png",
	hero = L"Assets/images/hero-introV5.jpg"; 

	ComponentManager& componentManager = *aFrame->getComponentManager();

	clock_t tStart = clock();

	srand(xThreadId);

	aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
	aFrame->setBackground(45, 45, 48);
	aFrame->setBorder(0xFF, 200, 200, 200, 1.0f);
	aFrame->setShadow(0xFF, 0, 0, 0, 10.0f);
	aFrame->setBounds(0, 0, 800, 600);
	aFrame->setLocationRelativeTo(NULL);

	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		
	Paint salmon(0xB9090BFF);
	Paint dark_black(0x11171cFF);
	Paint dark_black2(0x00000000);
	Paint dark_black3(0x222222FF);

	Panel& panel = *new Panel;
	G_SAFELY(panel.initialize());
	panel.setSize(Styles::PERCENTAGE, 100, Styles::PERCENTAGE, 100);
	panel.setBackgroundImage(hero);

	componentManager.add(root, panel);

	//Panel& main = *new Panel;
	//G_SAFELY(main.initialize());
	//main.setPosition(Styles::ABSOLUTE_);
	//main.setPositioning(Styles::PIXEL, 250, Styles::PIXEL, 0, Styles::PIXEL, 250, Styles::PIXEL, 0);
	//main.setSize(Styles::PIXEL, Styles::AUTO, Styles::PERCENTAGE, Styles::AUTO);
	//main.setDisplay(Styles::INLINE_BLOCK);
	//main.setBackgroundPaint(dark_black2);

	//componentManager.add(panel, main);
		
	Panel& item4 = *new Panel;
	G_SAFELY(item4.initialize());
	item4.setSize(Styles::PERCENTAGE, 100, Styles::PIXEL, 80);
	item4.setDisplay(Styles::BLOCK);
	item4.setMargins(Styles::PERCENTAGE, 0, Styles::PERCENTAGE, 0, Styles::PIXEL, 0, Styles::PIXEL, 20);
	item4.setBackgroundPaint(dark_black3);

	componentManager.add(panel, item4);
	
	Panel& item5 = *new Panel;
	G_SAFELY(item5.initialize());
	item5.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item5.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item5.setDisplay(Styles::INLINE_BLOCK);
	item5.setBackgroundImage(dvd2);

	componentManager.add(panel, item5);
	
	Panel& item6 = *new Panel;
	G_SAFELY(item6.initialize());
	item6.setSize(Styles::PIXEL, 165, Styles::PIXEL, 225);
	item6.setMargins(Styles::PERCENTAGE, 5, Styles::PERCENTAGE, 5, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item6.setDisplay(Styles::INLINE_BLOCK);
	item6.setBackgroundImage(dvd3);
	item6.addMouseListener(new MouseListener());

	componentManager.add(panel, item6);

	aFrame->setVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}