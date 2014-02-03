#include "ResizeListener.h"

using namespace A2D;

ResizeListener::ResizeListener(){}

ResizeListener::~ResizeListener(){}

void ResizeListener::mouseExited(MouseEvent * xEvent)
{
	Component * source = (Component*)xEvent->getSource();
	
	if (m_animation_height)
	{
		source->stop(m_animation_height);
		source->stop(m_animation_width);
	}

	m_animation_width = source->animate(Component::ANIMATE_WIDTH, Easing::OUT_QUAD, 50, 1000, NULL, NULL);
	m_animation_height = source->animate(Component::ANIMATE_HEIGHT, Easing::OUT_QUAD, 50, 1000, NULL, NULL);

	xEvent->setConsumed(true);
}

void ResizeListener::mouseEntered(MouseEvent * xEvent)
{
	Component * source = (Component*)xEvent->getSource();

	if (m_animation_height)
	{
		source->stop(m_animation_height);
		source->stop(m_animation_width);
	}

	m_animation_width = source->animate(Component::ANIMATE_WIDTH, Easing::OUT_QUAD, 200, 200, NULL, NULL);
	m_animation_height = source->animate(Component::ANIMATE_HEIGHT, Easing::OUT_QUAD, 200, 200, NULL, NULL);

	xEvent->setConsumed(true);
}
