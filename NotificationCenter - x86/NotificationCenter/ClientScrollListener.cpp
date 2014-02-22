#include "ClientScrollListener.h"

using namespace A2D;

ClientScrollListener::ClientScrollListener() :
m_scrollTopAnimation(Animator::COMPONENT_SCROLL_TOP, Easing::IN_OUT_QUART, -500, 2000, this, NULL, NULL),
m_scrollTopReturnAnimation(Animator::COMPONENT_SCROLL_TOP, Easing::IN_OUT_QUART, 0, 1200, this, NULL, NULL)
{
}

ClientScrollListener::~ClientScrollListener(){}

void ClientScrollListener::assignComponent(Component& x_component)
{
	m_scrollTopAnimation.m_arg = m_scrollTopReturnAnimation.m_arg = &x_component;
}

void ClientScrollListener::mouseExited(MouseEvent * xEvent)
{
	Component& source = *(Component*) xEvent->getSource();

	if (m_scroll_top)
	{
		Animator::stop(source, m_scroll_top);
	}

	source.captureScroll();

	m_scroll_top = Animator::animate(source, m_scrollTopReturnAnimation);

	xEvent->setConsumed(true);
}

void ClientScrollListener::callback(void * x_param)
{
	static_cast<Component*>(x_param)->releaseScroll();
}

void ClientScrollListener::mouseEntered(MouseEvent * xEvent)
{
	Component& source = *(Component*) xEvent->getSource();

	if (m_scroll_top)
	{
		Animator::stop(source, m_scroll_top);
	}

	source.captureScroll();

	m_scroll_top = Animator::animate(source, m_scrollTopAnimation);

	xEvent->setConsumed(true);
}
