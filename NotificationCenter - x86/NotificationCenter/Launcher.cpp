
#include "Launcher.h"
#include "CustomPanel.h"
#include "FadeListener.h"
#include "ResizeListener.h"
#include "BorderRadiiListener.h"

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
	wchar_t 
		*dvd1 = L"Assets/images/dvd1.jpg",
		*dvd2 = L"Assets/images/dvd2.jpg",
		*netflix = L"Assets/images/netflix.jpg",
		*dvd3 = L"Assets/images/circleTest.png",
		*sample = L"Assets/images/texture_sample.png",
		*hero = L"Assets/images/hero-introV5.jpg";

	const ComponentManager& componentManager = *aFrame->getComponentManager();

	timeblock__("Launcher started in - "){

		srand(xThreadId);

		aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
		aFrame->setBackground(45, 45, 48);
		aFrame->setBorder(0xFF, 200, 200, 200, 0.0f);
		aFrame->setShadow(0xFF, 0, 0, 0, 40.0f);
		aFrame->setBounds(0, 0, 800, 600);
		aFrame->setLocationRelativeTo(NULL);

		SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

		Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		
		Paint salmon(0xB9090BFF);
		Paint dark_black(0x11171cFF);
		Paint dark_black2(0x00000000);
		Paint darkRed(0x8A0809FF);

		Panel& panel = *new Panel;
		G_SAFELY(panel.initialize());
		panel.setId(0x4500);
		panel.setSize(Style::PERCENTAGE, 100, Style::PERCENTAGE, 100);
		panel.setBackgroundImage(hero);
		panel.setScroll(0, -100);

		componentManager.add(root, panel);
		
		Panel& item6 = *new Panel;
		G_SAFELY(item6.initialize());
		item6.setId(0x4502);
		item6.setSize(Style::PIXEL, 200, Style::PIXEL, 200);
		item6.setMargins(Style::PERCENTAGE, 10, Style::PERCENTAGE, 10, Style::PIXEL, 0, Style::PIXEL, 0);
		item6.setDisplay(Style::INLINE_BLOCK);
		item6.setBorderColor(0xB9090BFF, 0xB9090BFF, 0xB9090BFF, 0xB9090BFF);
		item6.setBorderWidths(Style::PIXEL, 0, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
		item6.setBorderRadii(Style::PIXEL, 100, Style::PIXEL, 100, Style::PIXEL, 100, Style::PIXEL, 100);
		item6.setBackgroundImage(dvd3);
		item6.addMouseListener(new FadeListener());

		componentManager.add(panel, item6);

		Panel& item7 = *new Panel;
		G_SAFELY(item7.initialize());
		item7.setId(0x4502);
		item7.setSize(Style::PIXEL, 200, Style::PIXEL, 200);
		item7.setMargins(Style::PERCENTAGE, 10, Style::PERCENTAGE, 10, Style::PIXEL, 0, Style::PIXEL, 0);
		item7.setDisplay(Style::INLINE_BLOCK);
		item7.setBorderColor(0xf10da2FF, 0xf10da2FF, 0xf10da2FF, 0xf10da2FF);
		item7.setBorderWidths(Style::PIXEL, 0, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
		item7.setBorderRadii(Style::PIXEL, 100, Style::PIXEL, 100, Style::PIXEL, 100, Style::PIXEL, 100);
		item7.setBackgroundImage(dvd3);
		item7.addMouseListener(new ResizeListener());

		componentManager.add(panel, item7);

		Panel& item8 = *new Panel;
		G_SAFELY(item8.initialize());
		item8.setId(0x4502);
		item8.setSize(Style::PIXEL, 200, Style::PIXEL, 200);
		item8.setMargins(Style::PERCENTAGE, 10, Style::PERCENTAGE, 10, Style::PIXEL, 0, Style::PIXEL, 0);
		item8.setDisplay(Style::INLINE_BLOCK);
		item8.setBorderColor(0x2ecc71FF, 0x2ecc71FF, 0x2ecc71FF, 0x2ecc71FF);
		item8.setBorderWidths(Style::PIXEL, 0, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
		item8.setBorderRadii(Style::PIXEL, 100, Style::PIXEL, 100, Style::PIXEL, 100, Style::PIXEL, 100);
		item8.setBackgroundImage(dvd3);
		item8.addMouseListener(new BorderRadiiListener());

		componentManager.add(panel, item8);
				
		aFrame->setVisible(true);
	}
}