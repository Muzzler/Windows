
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	Graphics& graphics = *aGraphics;

	if (aOptBackgroundSrc != NULL)
	{
		graphics.fillRect(&aPipeline, aOptBackgroundRegion, Paint::ASBESTOS);
	}
}