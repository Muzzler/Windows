#include "ClientScrollListener.h"

using namespace A2D;

ClientScrollListener::ClientScrollListener() :
m_scrollTopAnimation(Animator::COMPONENT_SCROLL_TOP, Easing::OUT_CUBIC, -3000, 2000, this, NULL, NULL)
{
	m_time = nanotime__;
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
	
	float z = Toolkit::SCROLL_DELTA;	

	if (((nanotime__ - m_time) * 1000.0f) < 400.0f && (m_last_z / z > 0))
	{
		return;
	}

	SYSOUT_FLT(z);

	m_time = nanotime__;
	m_last_z = z;

	if (m_scroll_top)
	{
		Animator::stop(source, m_scroll_top);
		source.releaseScroll();
	}
	
	if (z != 0.0f)
	{
		source.captureScroll();		
		m_scrollTopAnimation.m_to_a = source.getScrollTop() + z * 500;
		m_scroll_top = Animator::animate(source, m_scrollTopAnimation);
	}

	xEvent->setConsumed(true);
}
