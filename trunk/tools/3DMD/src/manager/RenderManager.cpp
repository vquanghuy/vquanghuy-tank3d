#include "rendermanager.h"

RenderManager::RenderManager():m_irrDevice(0)
{
}

RenderManager::~RenderManager()
{
}

bool RenderManager::initialize(QIrrlichtWidget *widget)
{
	if (widget == NULL)
		return false;

	m_qIrrWg = widget;
	m_irrDevice = m_qIrrWg->getIrrlichtDevice();

	return true;
}

IrrlichtDevice* RenderManager::getIrrlichtDevice()
{
	return m_irrDevice;
}

void RenderManager::setClearColor(video::SColor clearColor)
{
	m_clearColor = clearColor;

	m_qIrrWg->setClearColor(m_clearColor);
}