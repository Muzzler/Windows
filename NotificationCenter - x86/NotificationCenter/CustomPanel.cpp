
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	Graphics& graphics = *aGraphics;

		graphics.fillRect(&aPipeline, aOptBackgroundRegion, Paint::GREEN);
}