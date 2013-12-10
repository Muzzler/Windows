#ifndef __A2DTEXTURESHADER_H__
#define __A2DTEXTURESHADER_H__

//+-----------------------------------------------------------------------------
//
//  Class: 
//      A2DTEXTURESHADER
//
//  Synopsis:
//      Class that draw the textures.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////

#include <d3d10.h>
#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\D3DX10math.h"
#include <fstream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
// FORWARD DECLARATIONS
////////////////////////////////////////////////////////////////////////////////

using namespace std;


////////////////////////////////////////////////////////////////////////////////
// DEFINE
////////////////////////////////////////////////////////////////////////////////

#define FILENAME_LL(str1, str2)                               str1 str2

////////////////////////////////////////////////////////////////////////////////
// DECLARATION
////////////////////////////////////////////////////////////////////////////////

class A2DTextureShader
{
public:
	// Constructor
	A2DTextureShader();

	// Deconstructor
	~A2DTextureShader();

	// Variables
private:
	ID3D10Effect				*	aEffect;
	ID3D10EffectTechnique		*	aTechnique;
	ID3D10InputLayout			*	aLayout;

	ID3D10EffectMatrixVariable	*	aWorldMatrixPtr;
	ID3D10EffectMatrixVariable	*	aViewMatrixPtr;
	ID3D10EffectMatrixVariable	*	aProjectionMatrixPtr;

	ID3D10EffectShaderResourceVariable	*	aTexturePtr;

public:

	// Accessors
	// { NONE }

	// Mutators
	// { NONE }

	// Builders
	HRESULT							InitializeTextureShader(ID3D10Device * xDXDevice, HWND xHwnd);
	void							Shutdown();

	// Factory
	// { NONE }

	// Additional
	void							Render(ID3D10Device* xDXDevice, int xIndexCount, D3DXMATRIX xWorldMatrix, D3DXMATRIX xViewMatrix,
											D3DXMATRIX xProjectionMatrix, ID3D10ShaderResourceView* xTexture);

	// Pure Virtual
	// { NONE }

	// Virtual
	// { NONE }

	// Implementations

public:

	// Implementation
	// { A2DRENDERABLE }
	//virtual HRESULT                 CreateComponentResources(A2DRenderData * xRenderData);
	//virtual void                    DestroyComponentResources();

	// Implementation
	// { A2DABSTRACT }
	//virtual HRESULT					Initialize();
	//virtual void                    Deinitialize();
	//virtual LPCWSTR                 GetClass();
	//virtual LPCWSTR                 ToString();
	//virtual bool                    operator==(A2DAbstract * xAbstract);

private:
	HRESULT							InitializeShader(ID3D10Device * xDxDevice, HWND xHwnd, WCHAR * xFilename);
	void							ShutdownShader();
	void							OutputShaderErrorMessage(ID3D10Blob * xErrorMessage, HWND xHwnd, WCHAR* xShaderFilename);

	void							SetShaderParameters(D3DXMATRIX xWorldMatrix, D3DXMATRIX xViewMatrix, D3DXMATRIX xProjectionMatrix,
										ID3D10ShaderResourceView* xTexture);
	void							RenderShader(ID3D10Device* xDxDevice, int xIndexCount);
};


#endif
