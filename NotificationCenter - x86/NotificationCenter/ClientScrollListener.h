////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __CLIENTSCROLLLISTENER_H__
#define __CLIENTSCROLLLISTENER_H__

//+-----------------------------------------------------------------------------
//
//  Class: 
//     CLIENTSCROLLLISTENER
//
//  Synopsis:
//      Listener class for in mouse click events.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////

#include "../../../Aurora-SDK/Include/Core/ExtLibs.h"
#include "../../../Aurora-SDK/Include/Core/Component.h"
#include "../../../Aurora-SDK/Include/Core/MouseListener.h"

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

using namespace std;

namespace A2D {

	class ClientScrollListener : public MouseListener
	{
		HANIMATION				m_scroll_top = NULL;

		A2DCACHEDANIMATION		m_scrollTopAnimation;
		A2DCACHEDANIMATION		m_scrollTopReturnAnimation;

	public:
		ClientScrollListener();
		~ClientScrollListener();

		void					mouseExited(MouseEvent * xEvent);
		void					mouseEntered(MouseEvent * xEvent);
	};

}





#endif