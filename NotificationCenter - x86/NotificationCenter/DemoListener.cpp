
#include "DemoListener.h"

using namespace A2D;

DemoListener::DemoListener() : MouseListener() {}

void DemoListener::mousePressed(MouseEvent * xEvent)
{
	m_counter += 1;
	m_counter = m_counter % 8;

	Component * c = (Component*)xEvent->getSource();
	Label * label = (Label*)c;
	if (m_counter == 0)
	{
		label->setText("Aurora");
		label->setFontSize(2.3f);
		label->setShadowColor(new Color3D(0x00000000));
		label->setTextColor(&Color3D::WHITE);
		label->setMargins(Styles::PIXEL, 200, Styles::PIXEL, 150, Styles::PIXEL, 0, Styles::PIXEL, 0);
	}

	if (m_counter == 1)
	{
		label->setFontSize(2.7f);
		label->setMargins(Styles::PIXEL, 170, Styles::PIXEL, 160, Styles::PIXEL, 0, Styles::PIXEL, 0);
	}
	else if (m_counter == 2)
	{
		label->setTextColor(&Color3D::MIDNIGHT_BLUE);
	}
	else if (m_counter == 3)
	{
		label->setShadowColor(new Color3D(0x000000FF));
	}
	else if (m_counter == 4)
	{
		label->setShadowColor(new Color3D(0x000000A0));
	}
	else if (m_counter == 5)
	{
		label->setShadowColor(new Color3D(0x8E5157A0));
	}
	else if (m_counter == 6)
	{
		label->setShadowColor(new Color3D(0x0ce5c990));
	}
	else if (m_counter == 7)
	{
		label->setTextColor(new Color3D(0xbec0b8FF));
	}

	xEvent->setConsumed(true);
}
