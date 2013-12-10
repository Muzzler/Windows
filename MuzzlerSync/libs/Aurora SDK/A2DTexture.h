#ifndef __A2DTEXTURE_H__
#define __A2DTEXTURE_H__

//+-----------------------------------------------------------------------------
//
//  Class:  
//      A2DTEXTURE
//
//  Synopsis:
//      Texture container class.
//
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// INCLUDE
////////////////////////////////////////////////////////////////////////////////

#include <d3d10.h>
#include "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include\D3DX10.h"

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

class A2DTexture
{
public:
	// Constructor
	A2DTexture();

	// Deconstructor
	~A2DTexture();

	// Variables
	ID3D10ShaderResourceView	*	aTexture;
	// Accessors
	ID3D10ShaderResourceView	*	GetTexture();

	// Mutators
	// { NONE }

	// Builders
	HRESULT							CreateTexture(ID3D10Device * xDxDevice, WCHAR * xFilename);
	void							Shutdown();

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

	// Implementation
	// { A2DABSTRACT }
	//virtual HRESULT                 Initialize();
	//virtual void                    Deinitialize();
	//virtual LPCWSTR                 GetClass();
	//virtual LPCWSTR                 ToString();
	//virtual bool                    operator==(A2DAbstract * xAbstract);

};



#endif
