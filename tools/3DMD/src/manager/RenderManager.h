#ifndef RENDERMANAGER_H
#define RENDERMANAGER_H

#include "utils/Singleton.h"
#include "custom_widget\QIrrlichtWidget.h"

#include <irrlicht.h>
using namespace irr;

class RenderManager : public Singleton<RenderManager>
{
	friend class Singleton<RenderManager>;

private:
	QIrrlichtWidget			*m_qIrrWg;

	IrrlichtDevice			*m_irrDevice;
	video::SColorf			m_clearColor;

public:
	RenderManager();
	~RenderManager();

	bool				initialize(QIrrlichtWidget *widget);
	IrrlichtDevice*		getIrrlichtDevice();

	void				setClearColor(video::SColor clearColor);
};

#define GET_RENDER_MANAGER RenderManager::GetInstance()

#endif