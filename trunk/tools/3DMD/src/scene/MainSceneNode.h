#ifndef MAINSCENENODE_H
#define MAINSCENENODE_H

#include <irrlicht.h>

using namespace irr;

class MainSceneNode : public scene::ISceneNode
{
	core::aabbox3d<f32>		Box;
	video::S3DVertex		Vertices[4];
	video::SMaterial		Material;

public:
	MainSceneNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id);
	virtual void OnRegisterSceneNode();
	virtual void render();
	virtual const core::aabbox3d<f32>& getBoundingBox() const;
	virtual u32 getMaterialCount() const;
	virtual video::SMaterial& getMaterial(u32 i);
};


#endif