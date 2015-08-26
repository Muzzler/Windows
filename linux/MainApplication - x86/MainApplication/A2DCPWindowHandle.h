class A2DCPWindowHandle
{
public:
	A2DCPWindowHandle();

	~A2DCPWindowHandle();
#ifndef WIN32
	// code for X11
	Window			aHandle;
#else
	//  code for Windows
	HWND			 aHandle;
#endif

public:
//mutators and accessors

#ifndef WIN32
	Window			getWindowHandle();
	void			setWindowHandle(Window xHandle);
#else
	HWND			getWindowHandle();
	void			setWindowHandle(HWND xHandle);

#endif

};