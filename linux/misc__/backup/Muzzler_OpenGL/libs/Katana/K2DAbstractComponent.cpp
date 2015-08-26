
#include "../../include/K2DExtLibs.h"
#include "../../include/K2DAbstractComponent.h"
#include "../../include/K2DGraphics.h"

K2DAbstractComponent::K2DAbstractComponent() : 
aParentComp(NULL),
aGraphics(NULL) {}

K2DAbstractComponent::~K2DAbstractComponent(){}

void K2DAbstractComponent::Update()
{
    K2DGraphics * graphics = this->GetGraphics();

    // Create resources must be called first!!!
    if (graphics == NULL)   return;

    // Calling the render algorithm
    // -> Render component
    // -> Render its children on top
    // -> Render the border that overlays
    //    both of the previous renders.
    Render(graphics);
}

K2DGraphics * K2DAbstractComponent::GetGraphics()
{
    return aGraphics;
}
K2DAbstractComponent * K2DAbstractComponent::GetParent()
{
    return aParentComp;
}

void K2DAbstractComponent::SetBounds(K2DRect * xRect)
{
    K2DGraphics * graphics = GetGraphics();
    
    aOptRect.aWidth = xRect->aWidth;
    aOptRect.aHeight = xRect->aHeight;
    aOptRect.aX = xRect->aX;
    aOptRect.aY = xRect->aY;

    if (graphics)
    {
        graphics->Recalculate();
    }
}

void K2DAbstractComponent::Render(K2DRenderData * xRenderData)
{
    // Render the current component
    RenderComponent(xRenderData);

    // This will call children updates
    // This is sort of saying: (Render <==> Update)
    RenderChildren(xRenderData);

    // Render the currect component border
    RenderComponentBorder(xRenderData);
}

void K2DAbstractComponent::RenderChildren(K2DRenderData * xRenderData)
{
    for (int i = 0; i < aChildrenCompsIndex; i++)
    {
        // To render this. You have to call its children
        // update! This shows to update you have to call its
        // render and to render you are callings its update method.
        // A bit confusing but it's the best solution.
        aChildrenComps[i]->Update();
    }
}

void K2DAbstractComponent::AddComponent(K2DAbstractComponent * xAbstractComponent)
{
    K2DAbstractComponent ** newComponents;

    if (aChildrenCompsIndex >= aChildrenCompsIndex)
    {
        newComponents = CreateAmmoritizedComponentArray();
    //  delete[] aChildrenComps;
        aChildrenComps = newComponents;
    }

    aChildrenComps[aChildrenCompsIndex++] = xAbstractComponent;

    // Set the current component as the parent of the next
    xAbstractComponent->SetParent(this);
}

void K2DAbstractComponent::SetParent(K2DAbstractComponent * xComponent)
{
    aParentComp = xComponent;
}

K2DAbstractComponent** K2DAbstractComponent::CreateAmmoritizedComponentArray()
{
    K2DAbstractComponent ** newComponents;

    newComponents = new K2DAbstractComponent *[aChildrenCompsLength * 2];

    for (int i = 0; i < aChildrenCompsIndex; i++)
    {
        newComponents[i] = aChildrenComps[i];
    }

    aChildrenCompsLength *= 2;

    return newComponents;
}

string K2DAbstractComponent::GetClass()
{
    return "K2DAbstractComponent";
}

string K2DAbstractComponent::ToString()
{
    return "K2DAbstractComponent";
}

bool K2DAbstractComponent::operator==(K2DAbstract * xAbstract)
{
    return false;
}

/*
HRESULT A2DAbstractComponent::InitializeChildren()
{
    HRESULT hr = S_OK;

    for (int i = 0; i < aChildrenCompsIndex; i++)
    {
        if (aChildrenComps[i])
        {
            hr = aChildrenComps[i]->Initialize();
        }

        if (FAILED(hr)) return hr;
    }

    return hr;
}
*/

bool K2DAbstractComponent::Initialize()
{
    bool hr = S_OK;

    aChildrenComps = new K2DAbstractComponent *[aChildrenCompsLength = 5];

    // InitializeChildren();  // This will never do anything!!

    return hr;
}

void K2DAbstractComponent::Deinitialize()
{
    DeinitializeChildren();

    delete [] aChildrenComps;
}

void K2DAbstractComponent::DeinitializeChildren()
{
    for (int i = 0; i < aChildrenCompsIndex; i++)
    {
        aChildrenComps[i]->Deinitialize();
    }
}

// This will be a raw A2DRenderData. You can cast it to whatever you want!
bool K2DAbstractComponent::CreateResources(K2DRenderData * xRenderData)
{
    bool hr = S_OK;
    K2DGraphics * graphics;

    // Basic null check. If this pointer is null, then fail the
    // resources. The program must throw an exception and halt.
    if (xRenderData == NULL)    return E_FAIL;

    // This might be A2DRenderData or A2DGraphics. But we still have to make 
    // a new instance of it. But it will always be A2DGraphics from now on.
    graphics = (aGraphics = new K2DGraphics(this, xRenderData));

    // Initialize the unit
    hr = graphics->Initialize();

    if (FAILED(hr)) return hr;

    hr = CreateComponentResources(graphics); // These have to be type of A2DGraphics

    if (FAILED(hr)) return hr;

    hr = CreateChildrenResources(graphics); // These have to be type of A2DGraphics

    return hr;
}

void K2DAbstractComponent::DestroyResources()
{
    DestroyComponentResources();
    DestroyChildrenResources();
}

bool A2DAbstractComponent::CreateComponentResources(A2DRenderData * xRenderData)
{
    bool hr;
    K2DGraphics * graphics;

    // This is an example when of when I used A2DAbstract
    // Here, I have no need to do a dynamic typecast.
    // The method isClass is actually defined in the A2DAbstract
    // In fact, I just added this method recently, and I have it for
    // all objects instantly. No need to override it in any methods
    // in classes that extend A2DAbstract
    if (!xRenderData->isClass(L"K2DGraphics"))  return false;

    // Cast to A2DGraphics.
    // Similar to java.awt.Graphics to java.awt.Graphics2D
    graphics = (K2DGraphics *) xRenderData;

    // Tell graphics to call the render method once in order to
    // set aside only those resources.
    graphics->SetMode(K2D_GRAPHICS_MODE_CREATE);

    // A2DGraphics will call the parent Render method once
    hr = graphics->CreateResources();

    return hr;
}

void K2DAbstractComponent::DestroyComponentResources(){}

void K2DAbstractComponent::DestroyChildrenResources()
{
    for (int i = 0; i < aChildrenCompsIndex; i++)
    {
        aChildrenComps[i]->DestroyResources();
    }
}

bool K2DAbstractComponent::CreateChildrenResources(K2DRenderData * xRenderData)
{
    bool hr = NULL;

    for (int i = 0; i < aChildrenCompsIndex; i++)
    {
        hr = aChildrenComps[i]->CreateResources(xRenderData);

        if (FAILED(hr)) return hr;
    }

    return hr;
}

void K2DAbstractComponent::Add(K2DAbstractComponent * xAbstractComponent)
{
    AddComponent(xAbstractComponent);
}

void K2DAbstractComponent::RemoveComponent(K2DAbstractComponent * xAbstractComponent)
{
    // Fix later
}

LRESULT K2DAbstractComponent::WindowMsg(HWND * xHwnd, UINT * xMessage, WPARAM * xWParam, LPARAM * xLParam)
{
    // Fix later
    // Pass it all the children based on location!
    return NULL;
}

