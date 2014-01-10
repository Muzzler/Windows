
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	Graphics& graphics = *aGraphics;

	if (aOptBackgroundSrc != NULL)
	{
		bool repeat = aOptBackgroundProps.aOptRepeat == (_OPT_BACKGROUND_REPEAT_REPEAT_X | _OPT_BACKGROUND_REPEAT_REPEAT_Y);
		aOptBackgroundRegion.aX = -256;
		aOptBackgroundRegion.aY = -256;
		aOptBackgroundRegion.aWidth = 600 + 256;
		aOptBackgroundRegion.aHeight = 600 + 256;
		graphics.drawImage(&aPipeline, aOptBackgroundRegion, aOptBackgroundSrc, aOptBackgroundPaint, true);
	}
	else
	{
		graphics.fillRect(&aPipeline, aOptBackgroundRegion, aOptBackgroundPaint);
	}
}
