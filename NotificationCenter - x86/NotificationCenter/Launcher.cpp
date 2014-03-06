
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
	wchar_t * albumArt[] = { L"Assets/images/500px/art 1.jpg",
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
		aFrame->setBorder(0xFF, 200, 200, 200, 0.0f);
		aFrame->setShadow(0xFF, 0, 0, 0, 50.0f);
		aFrame->setBounds(0, 0, 1120, 840);
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

		panel.css_id(0x4500);
		panel.css_position(absolute);
		panel.css_size(100 pct, 100 pct);
		panel.css_background_image(background);
		panel.addActionListener(scrollMovement);

		int y = 0;

		for (int i = 0; i < 33; i++)
		{
			Panel& albumArtPanel = *new Panel;
			componentManager.add(panel, albumArtPanel);

			albumArtPanel.css_id(0x4500 | i);
			albumArtPanel.css_size(280 px, 280 px);
			albumArtPanel.css_display(block);
			albumArtPanel.css_background_image(albumArt[i]);

			if (i == 32)
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

		header.css_id(0x8550);
		header.css_background_blur(enable);
		header.css_position(absolute);
		header.css_positioning(250 px, 0 px, 0 px, automatic);
		header.css_size(automatic, 150 px);
		header.css_background_image(backgroundGray);

		//---------------------------------------------------------

		Panel& sidebar = *new Panel;
		componentManager.add(panel, sidebar);

		sidebar.css_id(0x8552);
		sidebar.css_background_blur(enable);
		sidebar.css_position(absolute);
		sidebar.css_background_image(backgroundGray);
		sidebar.css_positioning(left(0 px), top(0 px), right(automatic), bottom(0 px));		
		sidebar.css_size(width(250 px),	height(100 pct));

		//---------------------------------------------------------

		aFrame->setVisible(true);
	}
}