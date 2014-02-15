
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	if (!aVisible)
	{
		return;
	}

	Graphics& graphics = *aGraphics;

	//aOptBackgroundRegion.aWidth = 2048;
	//aOptBackgroundRegion.aHeight = 2048;

	//graphics.drawString(&aPipeline, aOptBackgroundRegion);
}
