////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __A2DATTRIBUTES_H__
#define __A2DATTRIBUTES_H__

//+-----------------------------------------------------------------------------
//
//  Struct:
//      A2DATTRIBUTES
//
//  Synopsis:
//      Differentiates which of the two possible arcs could match the given arc
//      parameters.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////

#include "A2DExtLibs.h"
#include "A2DAbstract.h"
#include "A2DWindow.h"

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////////////////////////

class A2D;
class A2DAbstract;
class A2DRenderable;
class A2DAbstractComponent;
class A2DCamera;
struct A2DCameraProperties;
struct A2DRenderData;
class A2DBackBuffer;
class A2DMatrixFactory;
class A2DModelFactory;
class A2DRootPane;
struct A2DWindowProperties;
class A2DWindow;
class A2DImagePanel;

////////////////////////////////////////////////////////////////////////////////
// DEFINE
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

struct A2DShared : public A2DAbstract
{

public:

	// Constructor
	A2DShared(HINSTANCE * xHInstance);

	// Deconstructor
	~A2DShared();

private:
	
	HINSTANCE				  *		aHInstance;
	A2DWindowProperties				aWindowProps;
	A2DCameraProperties				aCameraProps;
	A2DDXProperties					aDXProperties;
	A2DWindow				  *		aWindow;

public:
	// Accessors
	A2DWindowProperties       *     GetWindowProperties();
	A2DCameraProperties       *     GetCameraProperties();
	A2DDXProperties			  *     GetDXProperties();
	A2DWindow				  *     GetWindow();
	HINSTANCE				  *     GetHInstance();

	// Mutators
	A2DWindow				  *     SetWindow(A2DWindow * xWindow);

	// Builders
	// { NONE }

	// Factory
	// { NONE }

	// Additional
	// { NONE }

	// Pure Virtual
	// { NONE }

	// Virtual
	// { NONE }

	// Implementations
	// { NONE}

public:

	// Implementation
	// { A2DABSTRACT }
	virtual HRESULT                 Initialize();
	virtual void                    Deinitialize();
	virtual LPCWSTR                 GetClass();
	virtual LPCWSTR                 ToString();
	virtual bool                    operator==(A2DAbstract * xAbstract);
};

#endif