#pragma once

#include "../GraphicsModule.h"
#include "../../Utilities/Maths/Matrix4.h"

#include <vector>
#include <string>
//#include <Simple OpenGL Image Library\src\stb_image_aug.h>

class Skybox : public GraphicsModule
{
public:
	Skybox(const std::string identifier, const Matrix4 projmatrix,
		const Vector2 resolution, Matrix4* viewMatrix);
	~Skybox();

	void linkShaders() override;
	void regenerateShaders() override;

	void initialise() override;
	void apply() override;

	void setSkyboxTexture(unsigned int newTextureID)
	{
		textureID = newTextureID;
	}

	GLuint* GBufferFBO;

private:
	void initialiseMesh();
	void locateUniforms() override {}

	Matrix4* viewMatrix;
	Shader* skyboxShader;
	unsigned int textureID;
	unsigned int VAO, VBO;
};