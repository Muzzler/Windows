#include "ClientScrollListener.h"

using namespace A2D;

ClientScrollListener::ClientScrollListener() :
m_scrollTopAnimation(Animator::COMPONENT_SCROLL_TOP, Easing::OUT_CIRC, -200, 1000, NULL, NULL),
m_scrollTopReturnAnimation(Animator::COMPONENT_SCROLL_TOP, Easing::OUT_CIRC, 0, 500, NULL, NULL)
{
}

ClientScrollListener::~ClientScrollListener(){}

void ClientScrollListener::mouseExited(MouseEvent * xEvent)
{
	Component& source = *(Component*) xEvent->getSource();

	if (m_scroll_top)
	{
		Animator::stop(source, m_scroll_top);
	}

	m_scroll_top = Animator::animate(source, m_scrollTopReturnAnimation);

	xEvent->setConsumed(true);
}

void ClientScrollListener::mouseEntered(MouseEvent * xEvent)
{
	Component& source = *(Component*) xEvent->getSource();

	if (m_scroll_top)
	{
		Animator::stop(source, m_scroll_top);
	}

	m_scroll_top = Animator::animate(source, m_scrollTopAnimation);

	xEvent->setConsumed(true);
}
