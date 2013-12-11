#ifndef __A2DIMAGEPANEL_H__
#define __A2DIMAGEPANEL_H__

//+-----------------------------------------------------------------------------
//
//  Class: 
//      A2DIMAGEPANEL
//
//  Synopsis:
//      Texture quad.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////


#include "A2DTexture.h"

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// DEFINE
////////////////////////////////////////////////////////////////////////////////

#define FILENAME_LL(str1, str2)                               str1 str2

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

class A2DImagePanel 
	//public A2DAbstractComponent
{
	struct VertexType
	{
		D3DXVECTOR3 position;
		D3DXVECTOR2 texture;
	};

public:

	// Constructor
	A2DImagePanel();
	A2DImagePanel(ID3D10Device * xDXDevice, WCHAR* xTextureFName, int xPanelWidth, int xPanelHeight, int xInitX, int xInitY);
	// Deconstructor
	~A2DImagePanel();

private:

	// Variables
	int								aPanelWidth;
	int								aPanelHeight;
	int								aInitPosX;
	int								aInitPosY;
	int								aPrevPosX;
	int								aPrevPosY;
	/////temp/////--------------------------------
	int								aScreenWidth;
	int								aScreenHeight;
	int								aVertexCount;
	int								aIndexCount;
	ID3D10Buffer			*		aVertexBuffer;
	ID3D10Buffer			*		aIndexBuffer;
	////~temp/////--------------------------------
	//A2DRenderData			*		aRenderData;
	//A2DBufferData			*		aBufferData;
	//A2DQuadData				*		aQuadData;
	//A2DWindowProperties		*		aWindowProps;
	A2DTexture				*		aTexture;
	ID3D10Device			*		aDevice;
	WCHAR					*		aTextureFName;

public:

	// Accessors
	HRESULT Render(ID3D10Device* xDxDevice, int xPosX, int xPosY);
	int GetIndexCount();
	ID3D10ShaderResourceView* GetTexture();

	// Mutators
	void ShutdownBuffers();
	HRESULT UpdateBuffers(int xPosX, int xPosY);
	void RenderBuffers(ID3D10Device* xDxDevice);
	void ReleaseTexture();

	// Builders
	HRESULT InitializePanel(ID3D10Device* xDXDevice, int xScreenHeight, int xScreenWidth, WCHAR* xTextureFName, int xWidth, int xHeight);
	HRESULT InitializeBuffers(ID3D10Device * xDXDevice); // <- May ne the same device on the constructor.. so check on this l8er
	HRESULT LoadTexture(ID3D10Device* xDxDevice, WCHAR* xString);
	void Shutdown();

	// Factory
	// { NONE }

	// Additional
	// { NONE }

	// Pure Virtual
	// { NONE }

	// Virtual
	// { NONE }

public:

	// Implementations
	// { A2DABSTRACTCOMPONENT }
	//virtual void                    RenderComponent(A2DRenderData * xRenderData); // <-- will need (new) location x and y
	//virtual void                    RenderComponentBorder(A2DRenderData * xRenderData);
	//virtual void                    RenderComponentShadow(A2DRenderData * xRenderData);

public:

	// Implementation
	// { A2DRENDERABLE }
	//virtual HRESULT                 CreateComponentResources(A2DRenderData * xRenderData);
	//virtual void                    DestroyComponentResources();

public:
	
	// Implementation
	// { A2DABSTRACT }
	//virtual HRESULT                 Initialize();
	//virtual void                    Deinitialize();
	//virtual LPCWSTR                 GetClass();
	//virtual LPCWSTR                 ToString();
	//virtual bool                    operator==(A2DAbstract * xAbstract); 
};

#endif