
#include "../../include/A2DExtLibs.h"
#include "../../include/A2DGraphics.h"

A2DGraphics::A2DGraphics(A2DAbstractComponent * xComponent, A2DRenderData * xRenderData) :
aComponent(xComponent),
A2DRenderData(xRenderData)
{}

void A2DGraphics::DrawImage(A2DPipeline * xPipeline, LPCWSTR * xSrc, A2DRect * aRect, A2DImageProperties * xImageProps)
{
	A2DAbstractPipelineComponent * texture;
	A2DAbstractPipelineComponent * quad;
	A2DAbstractPipelineComponent * textureShader;

	if (xPipeline = NULL)
	{
		xPipeline = new A2DPipeline();

		texture = new A2DTexture(aBackBuffer, xSrc);
		quad = new A2DQuad(aBackBuffer, aRect);
		textureShader = new A2DTextureShader(aBackBuffer);

		quad->Initialize();
		texture->Initialize();
		textureShader->Initialize();

		void * textureArgs[] = { xSrc };
		void * quadArgs[] = { texture };
		void * textureShaderArgs[] = { aWorldMatrix, aViewMatrix, aProjectionMatrix, texture };

		texture->CreateResources(textureArgs);
		quad->CreateResources(quadArgs);
		textureShader->CreateResources(textureShaderArgs);
		
		xPipeline->aPipelineComps[0] = texture;
		xPipeline->aPipelineComps[1] = quad;
		xPipeline->aPipelineComps[2] = textureShader;

		xPipeline->aLength = 3;

		return;
	}

	texture = xPipeline->aPipelineComps[0];
	quad = xPipeline->aPipelineComps[1];
	textureShader = xPipeline->aPipelineComps[2];

	void * textureArgs[] = { xSrc };
	void * quadArgs[] = { texture, aRect, aWindowProps };
	void * textureShaderArgs[] = { texture };

	texture->Update(textureArgs);
	quad->Update(quadArgs);
	textureShader->CreateResources(textureShaderArgs);
				
	quad->Render();
	textureShader->Render();
}

void A2DGraphics::DrawImage(A2DPipeline * xPipeline,  A2DTexture * xTexture, float xImageLeft, float xImageTop, float xImageWidth, float xImageHeight, A2DImageProperties * xImageProps, int xBlur)
{	}

/////////////////////////////////////////////////////////////////////////////
// REQUIRED BY A2D_ABSTRACT
////////////////////////////////////////////////////////////////////////////

LPCWSTR A2DGraphics::GetClass()
{
	return L"A2DGraphics";
}

LPCWSTR A2DGraphics::ToString()
{
	return L"A2DGraphics";
}

bool A2DGraphics::operator==(A2DAbstract * xAbstract)
{
	return false;
}

void A2DGraphics::CalculateBounds()
{
	A2DRect * compRect, * parentRect;
	A2DAbstractComponent * parentComp;
	bool hasParent;

	parentComp  = aComponent->GetParent();
	hasParent = parentComp != NULL;
	parentRect = hasParent ? parentComp->GetBounds() : NULL;

	aBoundsLeft = (hasParent ? parentComp->GetGraphics()->aBoundsLeft : 0) + compRect->aX;
	aBoundsTop = (hasParent ? parentComp->GetGraphics()->aBoundsTop : 0) + compRect->aY;
	aBoundsWidth = min(compRect->aWidth, (hasParent ? parentRect->aWidth : INT_MAX));
	aBoundsHeight = min(compRect->aHeight, (hasParent ? parentRect->aHeight : INT_MAX));
}

void A2DGraphics::Recalculate()
{
	CalculateBounds();
}

HRESULT A2DGraphics::Initialize()
{
	HRESULT hr = S_OK;

	Recalculate();

	return hr;
}

void A2DGraphics::Deinitialize(){}