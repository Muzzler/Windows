// MuzzlerSyncService.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "NotificationDrawer.h"
/*
A2DRect * windowRect = A2DUtilities::CreateRect(0, 0, 1200, 700);

LPCWSTR file0 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 3.jpg";
LPCWSTR file1 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 4.jpg";
LPCWSTR file2 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [a] 5.jpg";
LPCWSTR file3 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureAlbumsWall [a] 1.jpg";
LPCWSTR file4 = L"libs/Aurora SDK/Lib/Assets/Images/muzzler windows-sync textureBackground [b] 1.png";
*/

int WINAPI WinMain( HINSTANCE xHInstance, HINSTANCE	xPrevInstance, LPSTR xLpCmdLine, int xCmdShow )
{
	UNREFERENCED_PARAMETER(xPrevInstance);
	UNREFERENCED_PARAMETER(xHInstance);

	// UPCOMING CHANGES (FINALIZED)
	//-------------------------------------
	// 1. Client does not touch the Properties/Preferences
	// 1. Client does not touch A2DWindow as well!!!!!!!!!!!!!!!!!!!!!!!
	// 2. Scrap all the Preferences crap from the client side! (it can cause too many issues)
	// 2. A2DWindowProperties will be a part of A2DPreferences. Just for structure purposes.
	// 3. A2D will create a A2DPreferences!!!!! Not client.
	//        -- BUT CLEAN THIS SHIT UP.
	// 4. It wiil validate + set everything it gets from A2DWindow into A2DPreferences
	// 5. Any changes (via A2DWindow#Propogate) will request A2D to check and redevelop the data from window

	A2DFrame aurora(); // Requires NOTHING TO BE PASSED IN and MADE ON STACK!
	//------------------------------------------------------------------------------------
	aurora.Initialize(); // Will be hidden from user soon.

	A2DWindow * window = aurora->GetWindow(); // Get from Aurora itself.
	// All these functions can be called at anytime during the runtime.
	// NOTE:::>>> All the following funcitons will have GET and SET.
	// IT IS IMPORTANT TO MAKE THIS PRIVATE/PUBLIC AS YOU WOULD EXPECT.
	//------------------------------------------------------------------------------------------------------------------
	window->SetName(L"Brent Enriquez WINDOW");	// Set A2DPreferences#WindowProperties + Window Title (Parent only) + Generate a random name for Child Window name. 
	// This is because no one cares about the Child name.
	// Set default values for these (A2DCommons.h), but can be edited by user during runtime.
	window->SetBounds(0, 0, 200, 700); // Edits A2DPreferences#WindowProperties via float
	window->SetBounds(windowRect);     // Edits A2DPreferences#WindowProperties via Rect
	window->SetSize(1200, 700);        // Edits A2DPreferences#WindowProperties float
	window->SetSize(windowDims);       // Edits A2DPreferences#WindowProperties via Dim
	window->SetUndecorated(true);      // Back to switching thing now...lol
	window->SetRelativeTo(NULL);       // NULL means just center it. Dont worry about other cases.
	window->SetVsync(true);            // A2DPreferences#WindowProperties + Set default values for these (A2DCommons.h), but can be edited by user during runtime.
	window->SetFullscreen(false);      // A2DPreferences#WindowProperties + Set default values for these (A2DCommons.h), but can be edited by user during runtime.
	window->SetDefaultCloseOperation(A2DWINDOW_EXIT_ON_CLOSE); // Close the whole application on disposing of frame (Look at Java#JFrame)
	// Set default values for these (A2DCommons.h), but can be edited by user during runtime.
	//------------------------------------------------------------------------------------------------------------------

	A2DRootPane * root = aurora->GetRootPane();
	
	A2DPanel * comp = new A2DPanel();
	comp->Initialize();// Will be hidden from user soon.

	A2DPanel * comp2 = new A2DPanel();
	comp2->Initialize();// Will be hidden from user soon.
	
	comp->SetBounds(200, 0, 1000, 120); // I will have both for this one...both integer and A2DRect *
	comp2->SetBounds(0, 0, 200, 700);

	root->SetOptBackgroundImage(&file3);
	comp->SetOptBackgroundImage(&file4);
	comp2->SetOptBackgroundImage(&file4);
	
	root->Add(comp);
	root->Add(comp2);

	root->SetDoubleBuffered(true);
	comp2->blurred = true;
	comp->blurred = true;

	// This will be the advanced shit.
	A2DUtilities.invokeLater(new A2DWorker()
	{
		public void run()
		{
			window->SetVisible(true);
		}
	});

	return 0;
}
