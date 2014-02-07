
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
	bar = L"Assets/images/dark_bar.jpg";

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
	Paint dark_black2(0xFFFFFFFF);
	Paint darkRed(0x8A0809FF);
	Paint silver(0xbdc3c7FF);

	/*Panel& main = *new Panel;
	G_SAFELY(main.initialize());
	main.setPosition(Styles::ABSOLUTE_);
	main.setPositioning(Styles::PIXEL, 250, Styles::PIXEL, 0, Styles::PIXEL, 250, Styles::PIXEL, 0);
	main.setSize(Styles::PIXEL, Styles::AUTO, Styles::PERCENTAGE, Styles::AUTO);
	main.setDisplay(Styles::INLINE_BLOCK);
	main.setBackgroundPaint(silver);*/

	Panel &main2 = *new Panel;
	G_SAFELY(main2.initialize());
	main2.setSize(Styles::PERCENTAGE, 100, Styles::PERCENTAGE, 100);
	main2.setBackgroundPaint(Paint::WHITE);

	componentManager.add(root, main2);

	//componentManager.add(root, main);

	Panel& panel = *new Panel;
	G_SAFELY(panel.initialize());
	panel.setSize(Styles::PIXEL, 600, Styles::PIXEL, 200);
	panel.setMargins(Styles::PIXEL, 0, Styles::PIXEL, 300, Styles::PIXEL, 0, Styles::PIXEL, 0);
	panel.setDisplay(Styles::INLINE_BLOCK);
	panel.setBackgroundImage(bar);

	componentManager.add(main2, panel);

	CustomPanel& item4 = *new CustomPanel;
	G_SAFELY(item4.initialize());
	//item4.setPosition(Styles::ABSOLUTE_);
	item4.setSize(Styles::PIXEL, 600, Styles::PIXEL, 200);
	item4.setMargins(Styles::PIXEL, 0, Styles::PIXEL, 0, Styles::PIXEL, 0, Styles::PIXEL, 0);
	item4.setDisplay(Styles::INLINE_BLOCK);
	item4.setBackgroundImage(sample);

	componentManager.add(panel, item4);

	aFrame->setVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}