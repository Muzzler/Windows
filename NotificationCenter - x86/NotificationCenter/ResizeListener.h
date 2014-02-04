////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __RESIZELISTENER_H__
#define __RESIZELISTENER_H__

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

	class ResizeListener : public MouseListener
	{
		Animation				m_animation_width = NULL;
		Animation				m_animation_height = NULL;
		
		A2DCACHEDANIMATION		m_widthShrinkAnimation;
		A2DCACHEDANIMATION		m_widthGrowthAnimation;
		
		A2DCACHEDANIMATION		m_heightShrinkAnimation;
		A2DCACHEDANIMATION		m_heightGrowthAnimation;

	public:
		ResizeListener();
		~ResizeListener();

		void					mouseExited(MouseEvent * xEvent);
		void					mouseEntered(MouseEvent * xEvent);
	};

}





#endif