#include "ClientScrollListener.h"

using namespace A2D;

ClientScrollListener::ClientScrollListener() :
m_scrollTopAnimation(Animator::COMPONENT_SCROLL_TOP, Easing::OUT_CUBIC, -3000, 2000, this, NULL, NULL)
{
}

ClientScrollListener::~ClientScrollListener(){}

void ClientScrollListener::assignComponent(Component& x_component)
{
	m_scrollTopAnimation.m_arg =  &x_component;
}

void ClientScrollListener::callback(void * x_param)
{
	static_cast<Component*>(x_param)->releaseScroll();
}

void ClientScrollListener::actionPerformed(ActionEvent * xEvent)
{
	Component& source = *(Component*) xEvent->getSource();
	
	if (m_scroll_top)
	{
		Animator::stop(source, m_scroll_top);
	}

	source.captureScroll();

	m_scrollTopAnimation.m_to_a = source.getScrollTop() + Toolkit::SCROLL_DELTA * 500;
	// m_scrollTopAnimation.m_period += abs__(Toolkit::SCROLL_DELTA) * 2000;

	m_scroll_top = Animator::animate(source, m_scrollTopAnimation);

	xEvent->setConsumed(true);
}
