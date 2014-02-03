////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __BORDERRADIILISTENER_H__
#define __BORDERRADIILISTENER_H__

//+-----------------------------------------------------------------------------
//
//  Class: 
//      FADELISTENER
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

	class BorderRadiiListener : public MouseListener
	{
		Animation				m_animation_radii = NULL;

	public:
		BorderRadiiListener();
		~BorderRadiiListener();

		void					mouseExited(MouseEvent * xEvent);
		void					mouseEntered(MouseEvent * xEvent);
	};

}





#endif