#pragma once
#include "Characters.h"
#include "GameObject.h"
#include <deque>
#include <SDL_image.h>


class Characters : public GameObject
{
public:

	Characters();
	virtual~Characters();

	//--------------------------------------------------- Initialize Shinisness
	void InitShininess(GLfloat Shininess);
	//--------------------------------------------------- Initialize Material Color
	void SetColors(glm::vec3 Ambient, glm::vec3 Diffuse, glm::vec3 Specular);
	//--------------------------------------------------- Render On Screen (Child)
	void Render(bool Textured, bool Mapped, bool Lit);
	//--------------------------------------------------- Object Update
	virtual void UpdateInputs();
	//--------------------------------------------------- Fill Buffers (Child)
	void FillBuffers();

protected:

	//--------------------------------------------------- Vertex Buffers
	GLuint VertexVBO;
	GLuint ColorVBO;
	GLuint NormalVBO;
	GLuint TextureVBO;
	GLuint TangentVBO;
	GLuint BiTangentVBO;
	GLuint EBO;
	GLuint VAO;
	//--------------------------------------------------- Mesh Material
	float ShininessMaterial;
	glm::vec3 AmbientMaterial;
	glm::vec3 DiffuseMaterial;
	glm::vec3 SpecularMaterial;
};