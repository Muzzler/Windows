
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

	aOptBackgroundRegion.aWidth = 330;
	aOptBackgroundRegion.aHeight = 420;

	graphics.drawString(&aPipeline, aOptBackgroundRegion);
}
