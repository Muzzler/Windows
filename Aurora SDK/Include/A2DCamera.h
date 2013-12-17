////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __A2DCAMERA_H__
#define __A2DCAMERA_H__

//+-----------------------------------------------------------------------------
//
//  Class:
//      A2DCAMERA
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

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////////////////////////

class A2D;
class A2DAbstract;
class A2DRenderable;
class A2DAbstractComponent;
class A2DCamera;
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

#define A2DCAMERA_LL(str1, str2)                              str1 str2

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

class A2DCamera : public A2DAbstract
{

public:

    // Constructor
    A2DCamera();

    // Deconstructor
    ~A2DCamera();

private:

    // Variables
	D3DXMATRIX                *     aViewMatrix;

	float                           aPositionX = 0.0f;
	float							aPositionY = 0.0f;
	float							aPositionZ = -10.0f;
	float							aRotationX = 0.0f;
	float							aRotationY = 0.0f;
	float							aRotationZ = 0.0f;
	float							aLookAtX = 0.0f;
	float							aLookAtY = 0.0f;
	float							aLookAtZ = 0.0f;
	float                           aLookAtXDef = 0.0f;
	float                           aLookAtYDef = 0.0f;
	float                           aLookAtZDef = 1.0f;

public:

    // Accesors
    D3DXMATRIX                *     GetViewMatrix();

private:

    // Builders
    // { NONE }

    // Factory
    // { NONE }

public:
    // Additional
	void						   CreateResources();

    // Pure Virtual
    // { NONE }

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
