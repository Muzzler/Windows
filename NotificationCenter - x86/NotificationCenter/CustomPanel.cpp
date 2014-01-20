
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	if (!m_visible)
	{
		return;
	}

	Graphics& graphics = *m_graphics;

	m_backgroundRegion.aWidth = 330;
	m_backgroundRegion.aHeight = 420;

	graphics.drawString(&m_pipeline, m_backgroundRegion);
}
