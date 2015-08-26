////////////////////////////////////////////////////////////////////////////////
// GAURDS
////////////////////////////////////////////////////////////////////////////////

#ifndef __K2DABSTRACTCOMPONENT_H__
#define __K2DABSTRACTCOMPONENT_H__

//+-----------------------------------------------------------------------------
//
//  Abstract Class:
//      A2DABSTRACTCOMPONENT
//
//  Synopsis:
//      Differentiates which of the two possible arcs could match the given arc
//      parameters.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////

#include "K2DRenderable.h"
#include "K2DRect.h"

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////////////////////////

class K2D;
class K2DAbstract;
class K2DRenderable;
class K2DCamera;
struct K2DCameraProperties;
struct K2DRenderData;
class K2DGraphics;
class K2DBackBuffer;
class K2DMatrixFactory;
class K2DModelFactory;
class K2DRootPane;
struct K2DWindowProperties;
class K2DWindow;

////////////////////////////////////////////////////////////////////////////////
// DEFINE
////////////////////////////////////////////////////////////////////////////////

#define K2DABSTRACTCOMPONENT_LL(str1, str2)                   str1 str2

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////


class K2DAbstractComponent : public K2DRenderable
{
public:

    // Constructor
    K2DAbstractComponent();

    // Deconstructor
    ~K2DAbstractComponent();

protected:

    // Variables
    K2DGraphics               *     aGraphics;
    K2DAbstractComponent      **    aChildrenComps;
    K2DAbstractComponent      *     aParentComp;
    int                             aChildrenCompsLength = 0;
    int                             aChildrenCompsIndex = 0;

    K2DRect                         aOptRect;

public:
    // Accessors
    K2DAbstractComponent      *     GetParent();
    K2DGraphics               *     GetGraphics();

public:

    // Accessors
    virtual K2DRect           *     GetBounds();

    // Mutators
    // { NONE }

private:

    // Builders
    K2DAbstractComponent      **    CreateAmmoritizedComponentArray();
    K2DGraphics               *     CreateGraphics();

    // Factory
    // { NONE }

public:

    // Additional
    void                            Add(K2DAbstractComponent * xAbstractComponent);

protected:

    // Additional
    void                            SetParent(K2DAbstractComponent * xComponent);

private:

    // Additional
    void                            RemoveComponent(K2DAbstractComponent * xAbstractComponent);
    void                            AddComponent(K2DAbstractComponent * xAbstractComponent);

public:

    // Pure Virtual
    virtual void                    RenderComponent(K2DRenderData * xRenderData) = 0;
    virtual void                    RenderComponentBorder(K2DRenderData * xRenderData) = 0;

public:

    // Virtual
    virtual void                    SetBounds(K2DRect * xRect);

protected:

    // Virtual
    virtual LRESULT                 WindowMsg(HWND * xHwnd, UINT * xMessage, WPARAM * xWParam, LPARAM * xLParam);
    virtual void                    RenderChildren(A2DRenderData * xRenderData);
    virtual HRESULT                 CreateChildrenResources(K2DRenderData * xRenderData) final;
//  virtual HRESULT                 InitializeChildren() final;
    virtual void                    DeinitializeChildren() final;
    virtual void                    DestroyChildrenResources() final;

public:

    // Virtual
    virtual HRESULT                 CreateComponentResources(K2DRenderData * xRenderData) final;
    virtual void                    DestroyComponentResources() final;
    virtual void                    Render(A2DRenderData * xRenderData);


public:

    // Virtual
    // { A2DRENDERABLE }
    virtual void                    Update() final;
    virtual HRESULT                 CreateResources(K2DRenderData * xRenderData) final;
    virtual void                    DestroyResources() final;

public:

    // Implementation
    // { A2DABSTRACT }
    virtual HRESULT                 Initialize();
    virtual void                    Deinitialize();
    virtual LPCWSTR                 GetClass();
    virtual LPCWSTR                 ToString();
    virtual bool                    operator==(K2DAbstract * xAbstract);

};

#endif
