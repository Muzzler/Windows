
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	Graphics& graphics = *aGraphics;

	graphics.drawString(&aPipeline, aOptBackgroundRegion);
}
