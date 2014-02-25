
#include "CustomPanel.h"

using namespace A2D;

class Launcher : public Runnable
{
public:
	Launcher(HINSTANCE xHINSTANCE);

	void runOnEventDispatchingThread();
	void runOnMainThread();

private:
	Frame * aFrame;
	void run(void * x_param, int xThreadId);

	ComponentManager * aComponentManager;
	
	LPCTSTR file0 = L"Assets/images/free [a] 1.jpg",
		file1 = L"Assets/images/muzzler windows-sync textureBackground [a] 1.jpg",
		file2 = L"Assets/images/muzzler windows-sync background [a] 1.jpg",
		file3 = L"Assets/images/muzzler windows-sync textureBackground [a] 1.jpg",
		file4 = L"Assets/images/muzzler windows-sync textureLogo [a] 1.png",
		title = L"Muzzler - Notification Center";

};