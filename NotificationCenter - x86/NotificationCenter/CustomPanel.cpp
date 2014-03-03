
#include "CustomPanel.h"

using namespace A2D;

CustomPanel::CustomPanel() : Component() {}

void CustomPanel::paintComponent()
{
	if (!m_styleSet.m_visible)
	{
		return;
	}

	Graphics& graphics = *m_graphics;

	m_backgroundRegion.m_width = 330;
	m_backgroundRegion.m_height = 420;

//	graphics.drawString(&m_pipeline, m_backgroundRegion);
}
