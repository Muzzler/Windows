
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

void Launcher::run(int xThreadId)
{
	wchar_t * background = L"Assets/images/background radial-black.jpg";
	wchar_t * albumArt [] = { L"Assets/images/album-art/art 1.jpg",
							  L"Assets/images/album-art/art 2.jpg",
							  L"Assets/images/album-art/art 3.jpg",
							  L"Assets/images/album-art/art 4.jpg",
							  L"Assets/images/album-art/art 5.jpg",
							  L"Assets/images/album-art/art 6.jpg",
							  L"Assets/images/album-art/art 7.jpg",
							  L"Assets/images/album-art/art 8.jpg" };

	const ComponentManager& componentManager = *aFrame->getComponentManager();

	timeblock__("Launcher started in - "){

		srand(xThreadId);

		aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
		aFrame->setBackground(45, 45, 48);
		aFrame->setBorder(0xFF, 200, 200, 200, 0.0f);
		aFrame->setShadow(0xFF, 0, 0, 0, 40.0f);
		aFrame->setBounds(0, 0, 900, 600);
		aFrame->setLocationRelativeTo(NULL);

		SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

		Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		G_SAFELY(root.initialize());
		root.setBackgroundImage(background); // Force to black

		Panel& panel = *new Panel;
		G_SAFELY(panel.initialize());
		panel.setId(0x4500);
		panel.setBorderColor(0, 0xFFFFFF33, 0, 0);
		panel.setBorderWidths(Style::PIXEL, 0, Style::PIXEL, 1, Style::PIXEL, 0, Style::PIXEL, 0);
		panel.setPosition(Style::Position::ABSOLUTE_);
		panel.setPositioning(Style::PIXEL, 0, Style::PIXEL, 1, Style::PIXEL, 0, Style::PIXEL, 0);
		panel.setBackgroundImage(background);
		panel.addMouseListener(new ClientScrollListener());

		componentManager.add(root, panel);
		
		for (int i = 0; i < 8; i++)
		{
			Panel& albumArtPanel = *new Panel;
			G_SAFELY(albumArtPanel.initialize());
			albumArtPanel.setId(0x4500 | i);
			albumArtPanel.setSize(Style::PIXEL, 300, Style::PIXEL, 300);
			albumArtPanel.setDisplay(Style::INLINE_BLOCK);
		//	albumArtPanel.setBorderColor(0xB9090BFF, 0xB9090BFF, 0xB9090BFF, 0xB9090BFF);
		//	albumArtPanel.setBorderRadii(Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
			albumArtPanel.setBackgroundImage(albumArt[i]);

			componentManager.add(panel, albumArtPanel);
		}

		for (int i = 0; i < 8; i++)
		{
			Panel& albumArtPanel = *new Panel;
			G_SAFELY(albumArtPanel.initialize());
			albumArtPanel.setId(0x4500 | i);
			albumArtPanel.setSize(Style::PIXEL, 300, Style::PIXEL, 300);
			albumArtPanel.setDisplay(Style::INLINE_BLOCK);
			//	albumArtPanel.setBorderColor(0xB9090BFF, 0xB9090BFF, 0xB9090BFF, 0xB9090BFF);
			//	albumArtPanel.setBorderRadii(Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10, Style::PIXEL, 10);
			albumArtPanel.setBackgroundImage(albumArt[i]);

			componentManager.add(panel, albumArtPanel);
		}
		aFrame->setVisible(true);
	}
}