
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
	wchar_t * background = L"Assets/images/background black.jpg";
	wchar_t * backgroundGray = L"Assets/images/background gray translucent.png";
	wchar_t * albumArt [] = { L"Assets/images/album-art/art 1.jpg",
							  L"Assets/images/album-art/art 2.jpg",
							  L"Assets/images/album-art/art 3.jpg",
							  L"Assets/images/album-art/art 4.jpg",
							  L"Assets/images/album-art/art 5.jpg",
							  L"Assets/images/album-art/art 6.jpg",
							  L"Assets/images/album-art/art 7.jpg",
							  L"Assets/images/album-art/art 8.jpg",
							  L"Assets/images/album-art/art 9.jpg", };

	const ComponentManager& componentManager = *aFrame->getComponentManager();

	timeblock__("Launcher started in - "){

		srand(xThreadId);

		aFrame->setName(L"Muzzler - Notification Center");                                // Set the title
		aFrame->setBackground(45, 45, 48);
		aFrame->setBorder(0xFF, 200, 200, 200, 0.0f);
		aFrame->setShadow(0xFF, 0, 0, 0, 50.0f);
		aFrame->setBounds(0, 0, 569, 569);
		aFrame->setLocationRelativeTo(NULL);

		SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

		//---------------------------------------------------------

		Panel& root = aFrame->getRootPane(); // Reference to make syntax easier
		root.setBackgroundImage(background); // Force to black

		//---------------------------------------------------------

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
		panel.addActionListener(scrollMovement);


		int y = 0;

		for (int i = 0; i < 9; i++)
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

			if (i == 8)
			{
				if (y++ < 15)
				{
					i = 0;
				}
			}
		}

		//---------------------------------------------------------
		
		Panel& header = *new Panel;
		componentManager.add(panel, header);

		header.setId(0x8550);
		header.setDoubleBuffered(true);
		header.setPosition(Style::Position::ABSOLUTE_);
		header.setPositioning(Style::PIXEL, 0, Style::PIXEL, 0, Style::PIXEL, 0, Style::PIXEL, Style::AUTO);
		header.setSize(Style::PIXEL, Style::AUTO, Style::PIXEL, 150);
		header.setBackgroundImage(backgroundGray);

		//---------------------------------------------------------

		aFrame->setVisible(true);
	}
}