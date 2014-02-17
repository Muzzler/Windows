#include "FadeListener.h"

using namespace A2D;

FadeListener::FadeListener(){}

FadeListener::~FadeListener(){}

void FadeListener::mouseExited(MouseEvent * xEvent)
{
	Component * source = (Component*)xEvent->getSource();

	if (m_animation)
	{
		source->stop(m_animation);
	}

	m_animation = source->animate(Component::ANIMATE_OPACITY, Easing::OUT_QUAD, 0.2f, 1000, NULL, NULL);
}

void FadeListener::mouseEntered(MouseEvent * xEvent)
{
	Component * source = (Component*)xEvent->getSource();

	if (m_animation)
	{
		source->stop(m_animation);
	}

	m_animation = source->animate(Component::ANIMATE_OPACITY, Easing::IN_QUAD, 1.0f, 200, NULL, NULL);
}
