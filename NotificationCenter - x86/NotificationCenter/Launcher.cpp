
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
	aFrame->setBorder(0xFF, 0, 122, 204, 10.0f);
	aFrame->setShadow(0xFF, 0, 122, 204, 10.0f);
	aFrame->setBounds(0, 0, 800, 600);
	aFrame->setLocationRelativeTo(NULL);
	//aFrame->getWindow()->addWindowListener(new WindowListener());
	//aFrame->addMouseMotionListener(new MouseMotionListener());
	//aFrame->addMouseListener(new MouseListener());

	SYSOUT_F("%s - 0x%X\n", (xThreadId == 0 ? "Main Thread" : "Event Dispatching Thread"), xThreadId);

	Panel& root = aFrame->getRootPane(); // Reference to make syntax easier

	Panel& panel = *new Panel;
	G_SAFELY(panel.initialize());
	panel.setBounds(20, 20, 400, 400);
	panel.setBackgroundImage(file4);
	panel.setBackgroundPaint(Paint::GREEN_SEA_TO_POMEGRANATE_VERTICAL);
	panel.addMouseListener(new MouseListener());
	// panel.addListenerThroughChildren(new MouseListener()); // doesnt work as intended.
	//panel.addMouseMotionListener(new MouseMotionListener());


	CustomPanel& customPanel = *new CustomPanel;
	G_SAFELY(customPanel.initialize());
	customPanel.setBounds(20, 20, 200, 200);
	customPanel.setBackgroundImage(file4);
	//customPanel.addMouseListener(new MouseListener());
	//customPanel.addMouseMotionListener(new MouseMotionListener());
	//customPanel.addFocusListener(new FocusListener());

	Panel& panel2 = *new Panel;
	G_SAFELY(panel2.initialize());
	panel2.setBounds(20, 20, 100, 400);
	panel2.setBackgroundImage(file4);

	ImageProperties& props = panel2.getBackgroundProperties();
	props.aOptRepeat = _OPT_BACKGROUND_REPEAT_NO_REPEAT;
	panel2.setBackgroundProperties(props);
	panel2.setBackgroundPaint(Paint::EMERALD);

	//panel2.addFocusListener(new FocusListener());

	OrderedList<Panel*> panelList;
	Panel * panelX;
	Panel * panelY = &root;
	for (int i = 0; i < 100000; i += 1)
	{
		panelX = new Panel;
		G_SAFELY(panelX->initialize());
		panelX->setBounds(20, 20, 400, 400);
		panelX->setBackgroundImage(file4);
		repaintManager.add(*panelY, *panelX);
		panelY = panelX;
	}

	//repaintManager.add(root, panel);
	//repaintManager.add(panel, customPanel);
	//repaintManager.add(customPanel, panel2);

	aFrame->setVisible(true);

	SYSOUT_F("Time taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}