////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __FADELISTENER_H__
#define __FADELISTENER_H__

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

	class FadeListener : public MouseListener
	{
	public:
		FadeListener();
		~FadeListener();

		void					mouseExited(MouseEvent * xEvent);
		void					mouseEntered(MouseEvent * xEvent);
	};

}





#endif