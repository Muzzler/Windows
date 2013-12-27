
#include "NotificationCenter.h"

class Launcher : public A2DRunnable
{
public:
	Launcher(HINSTANCE xHINSTANCE);

	void runOnEventDispatchingThread();
	void runOnMainThread();

private:
	A2DFrame * aFrame;
	void run(int xThreadId);

	A2DPanel mainPanel;
	A2DPanel subPanel;


	LPCTSTR file0 = L"Assets/images/free [a] 1.jpg",
		file1 = L"Assets/images/muzzler windows-sync textureBackground [a] 1.jpg",
		file2 = L"Assets/images/muzzler windows-sync background [a] 1.jpg",
		file3 = L"Assets/images/muzzler windows-sync textureBackground [a] 1.jpg",
		file4 = L"Assets/images/muzzler windows-sync textureBackground [a] 2.jpg",
		title = L"Muzzler - Notification Center";

};