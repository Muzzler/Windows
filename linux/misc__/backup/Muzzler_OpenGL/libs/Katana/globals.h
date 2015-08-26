#ifndef A_H
#define A_H

/////////////////////////////////////////////////////////////////////////////
//
// AURORA (A)
//
/////////////////////////////////////////////////////////////////////////////

#include "resources.h"
#include "settings.h"

/////////////////////////////////////////////////////////////////////////////
//
// ADDITIONAL LIBS
//
/////////////////////////////////////////////////////////////////////////////

#include "../Aurora/globals.h"

/////////////////////////////////////////////////////////////////////////////
//
// A: ESSENTIALS
//
/////////////////////////////////////////////////////////////////////////////

#define MAX_LOADSTRING 100
#define LL_A(str1, str2)											str1 str2

/////////////////////////////////////////////////////////////////////////////
//
// A: CLASS DECLARATION
//
/////////////////////////////////////////////////////////////////////////////

class Aurora
{
public:
	Aurora();
	~Aurora();

	HRESULT Initialize();
	HRESULT Shutdown();
	HRESULT Run();

	// ALL PARAMTERS WITH x AS STARTING letter;

	HRESULT SetSize(INT xWidth, INT xHeight);
	HRESULT SetCamera(AuroraCamera * xCamera);
	HRESULT SetProjection(AuroraProjection * xProjection);
	HRESULT SetRootPane(AuroraRootPane xRootPane);

private:
	HRESULT CreateGraphics();

private:
	HWND aHwnd;
	HINSTANCE aHistance;

	AuroraGraphics 	 * 	aGraphics;
	AuroraCamera 	 * 	aCamera;
	AuroraProjection * 	aProjection;
	AuroraRootPane   * 	aRootPane;

	// The windows procedure.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	WindowProperties * 	mWinProps;
};

#endif
