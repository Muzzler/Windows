////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __A2DPIPELINECOMPONENT_H__
#define __A2DPIPELINECOMPONENT_H__

//+-----------------------------------------------------------------------------
//
//  Class:
//      A2DPIPELINECOMPONENT
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
#include "A2DAbstractPipelineComponent.h"

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

////////////////////////////////////////////////////////////////////////////////
// DEFINE
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

class A2DPipelineComponent : public A2DAbstractPipelineComponent
{

public:

	// Constructor
	A2DPipelineComponent(A2DBackBuffer * aBackBuffer);

	// Deconstructor
	~A2DPipelineComponent();


public:

	// Pure Virtual
	virtual HRESULT					CreateResources(void * xArgs[]) = 0;
	virtual void					Update(void * xArgs[]) = 0;
	virtual void					Render() = 0; // Render should be defined seperately but called inside Update
	virtual void					DestroyResources();

	// Virtual
	// { NONE }

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
