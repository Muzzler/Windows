#include "ResizeListener.h"

using namespace A2D;

ResizeListener::ResizeListener() : 
	m_widthShrinkAnimation(Animator::COMPONENT_WIDTH, Easing::OUT_QUAD, 50, 1000, NULL, NULL),
	m_widthGrowthAnimation(Animator::COMPONENT_WIDTH, Easing::OUT_ELASTIC, 200, 1000, NULL, NULL),
	m_heightShrinkAnimation(Animator::COMPONENT_HEIGHT, Easing::OUT_QUAD, 50, 1000, NULL, NULL),
	m_heightGrowthAnimation(Animator::COMPONENT_HEIGHT, Easing::OUT_ELASTIC, 200, 1000, NULL, NULL)
{
}

ResizeListener::~ResizeListener(){}

void ResizeListener::mouseExited(MouseEvent * xEvent)
{
	Component& source = *(Component*)xEvent->getSource();
	
	if (m_animation_height)
	{
		Animator::stop(source, m_animation_width);
		Animator::stop(source, m_animation_height);
	}

	m_animation_width = Animator::animate(source, m_widthShrinkAnimation);
	m_animation_height = Animator::animate(source, m_heightShrinkAnimation);

	xEvent->setConsumed(true);
}

void ResizeListener::mouseEntered(MouseEvent * xEvent)
{
	Component& source = *(Component*)xEvent->getSource();

	if (m_animation_height)
	{
		Animator::stop(source, m_animation_width);
		Animator::stop(source, m_animation_height);
	}

	m_animation_width = Animator::animate(source, m_widthGrowthAnimation);
	m_animation_height = Animator::animate(source, m_heightGrowthAnimation);

	xEvent->setConsumed(true);
}
