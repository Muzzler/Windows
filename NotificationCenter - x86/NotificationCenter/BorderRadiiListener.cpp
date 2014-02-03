#include "BorderRadiiListener.h"

using namespace A2D;

BorderRadiiListener::BorderRadiiListener(){}

BorderRadiiListener::~BorderRadiiListener(){}

void BorderRadiiListener::mouseExited(MouseEvent * xEvent)
{
	Component * source = (Component*)xEvent->getSource();

	if (m_animation_radii)
	{
		source->stop(m_animation_radii);
	}

	m_animation_radii = source->animate(Component::ANIMATE_BORDER_RADII_UNIFIED, Easing::OUT_QUAD, 0, 1000, NULL, NULL);
	xEvent->setConsumed(true);
}

void BorderRadiiListener::mouseEntered(MouseEvent * xEvent)
{
	Component * source = (Component*)xEvent->getSource();

	if (m_animation_radii)
	{
		source->stop(m_animation_radii);
	}

	m_animation_radii = source->animate(Component::ANIMATE_BORDER_RADII_UNIFIED, Easing::OUT_QUAD, 100, 200, NULL, NULL);


	xEvent->setConsumed(true);
}
