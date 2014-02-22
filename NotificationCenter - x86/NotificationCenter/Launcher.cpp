
#include "Launcher.h"
#include "CustomPanel.h"
#include "FadeListener.h"
#include "ResizeListener.h"
#include "BorderRadiiListener.h"
#include "ClientScrollListener.h"

Launcher::Launcher(HINSTANCE xHInstance)
{
	aFrame = new Frame(xHInstance);
}

void Launcher::runOnEventDispatchingThread()
{
	G_SAFELY(aFrame->initialize());
	
	Toolkit::getSystemEventQueue(aFrame->id())->invokeLater(this); // To create the window!
}

void Launcher::run(void * x_param, int xThreadId)
{
	wchar_t * background = L"Assets/images/background radial-black.jpg";
	wchar_t * albumArt [] = { L"Assets/images/500px/art 1.jpg",
							  L"Assets/images/500px/art 2.jpg",
							  L"Assets/images/500px/art 3.jpg",
							  L"Assets/images/500px/art 4.jpg",
							  L"Assets/images/500px/art 5.jpg",
							  L"Assets/images/500px/art 6.jpg",
							  L"Assets/images/500px/art 7.jpg",
							  L"Assets/images/500px/art 8.jpg",
							  L"Assets/images/500px/art 9.jpg",
							  L"Assets/images/500px/art 10.jpg",
							  L"Assets/images/500px/art 11.jpg",
							  L"Assets/images/500px/art 12.jpg",
							  L"Assets/images/500px/art 13.jpg",
							  L"Assets/images/500px/art 14.jpg",
							  L"Assets/images/500px/art 15.jpg",
							  L"Assets/images/500px/art 16.jpg",
							  L"Assets/images/500px/art 17.jpg",
							  L"Assets/images/500px/art 18.jpg",
							  L"Assets/images/500px/art 19.jpg",
							  L"Assets/images/500px/art 20.jpg",
							  L"Assets/images/500px/art 21.jpg",
							  L"Assets/images/500px/art 22.jpg",
							  L"Assets/images/500px/art 23.jpg",
							  L"Assets/images/500px/art 24.jpg",
							  L"Assets/images/500px/art 25.jpg",
							  L"Assets/images/500px/art 26.jpg",
							  L"Assets/images/500px/art 27.jpg",
							  L"Assets/images/500px/art 28.jpg",
							  L"Assets/images/500px/art 29.jpg",
							  L"Assets/images/500px/art 30.jpg",
							  L"Assets/images/500px/art 31.jpg",
							  L"Assets/images/500px/art 32.jpg",
							  L"Assets/images/500px/art 33.jpg" };

	const ComponentManager& componentManager = *aFrame->getComponentManager();

	timeblock__("Launcher started in - "){

		srand(xThreadId);

		aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
		aFrame->setBackground(45, 45, 48);
		aFrame->setBorder(0xFF, 200, 200, 200, 1.0f);
		aFrame->setShadow(0x55, 0, 0, 0, 20.0f);
		aFrame->setBounds(0, 0, 853, 853);
		aFrame->setLocationRelativeTo(NULL);

		SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

		Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		root.setBackgroundImage(background); // Force to black

		Panel& panel = *new Panel;
		componentManager.add(root, panel);

		ClientScrollListener * scrollMovement = new ClientScrollListener();
		scrollMovement->assignComponent(panel);

		panel.setId(0x4500);/*
		panel.setBorderColor(0, 0xFFFFFF33, 0, 0);
		panel.setBorderWidths(Style::PIXEL, 0, Style::PIXEL, 1, Style::PIXEL, 0, Style::PIXEL, 0);*/
		panel.setPosition(Style::Position::ABSOLUTE_);
		panel.setPositioning(Style::PIXEL, 0, Style::PIXEL, 0, Style::PIXEL, 0, Style::PIXEL, 0);
		panel.setBackgroundImage(background);
		panel.addMouseListener(scrollMovement);
		
		for (int i = 0; i < 33; i++)
		{
			Panel& albumArtPanel = *new Panel;
			componentManager.add(panel, albumArtPanel);

			albumArtPanel.setId(0x4500 | i);
			albumArtPanel.setMargins(Style::PIXEL, 3, Style::PIXEL, 3, Style::PIXEL, 0, Style::PIXEL, 0);
			albumArtPanel.setSize(Style::PIXEL, 280, Style::PIXEL, 280);
			albumArtPanel.setDisplay(Style::INLINE_BLOCK);
			//albumArtPanel.setBorderColor(0xB9090BFF, 0xB9FF0BFF, 0xB90FFBFF, 0xB9090BFF);
			//albumArtPanel.setBorderWidths(Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
			//albumArtPanel.setBorderRadii(Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
			albumArtPanel.setBackgroundImage(albumArt[i]);
		}

		aFrame->setVisible(true);
	}
}