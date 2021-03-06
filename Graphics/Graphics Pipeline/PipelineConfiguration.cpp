#include "PipelineConfiguration.h"
#include "Graphics Settings/BasicGeometry.h"

PipelineConfiguration::PipelineConfiguration()
{
	this->sceneManager = nullptr;
	this->window = nullptr;
	this->resolution = Vector2();
	this->camera = nullptr;
	this->pipeline = nullptr;
}

PipelineConfiguration::PipelineConfiguration(SceneManager* sceneManager, Window* window, 
	Camera* camera, Vector2 resolution)
{
	this->sceneManager = sceneManager;
	this->window = window;
	this->resolution = resolution;
	this->camera = camera;
	this->pipeline = pipeline;
}


PipelineConfiguration::~PipelineConfiguration()
{
}

void PipelineConfiguration::initialiseModules(Matrix4 projmatrix)
{
	basicGeom = new BasicGeometry("Basic Geometry Renderer", projmatrix, resolution, camera, sceneManager->getSubMeshesInFrustum());
	basicGeom->linkShaders();
}

void PipelineConfiguration::buildPipeline(GraphicsPipeline* pipeline)
{
	pipeline->addModule(basicGeom);
}
