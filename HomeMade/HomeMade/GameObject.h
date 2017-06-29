#pragma once
#include"ShaderManager.h"
#include"TextureManager.h"
#include"ModelManager.h"
#include<gtc\matrix_transform.hpp> 

class GameObject
{
public:

	GameObject();
	virtual~GameObject();

	//--------------------------------------------------- Initial Transformations
	void InitPosition(glm::vec3 Coords);
	void InitRotation(glm::vec3 Rotations);
	void InitScale(glm::vec3 Scales);
	//--------------------------------------------------- Initial Target
	void SetTarget(glm::vec3 Taget);
	//--------------------------------------------------- Get/Enable Attribute IDs
	static void SetAttributes();
	static void UnSetAttributes();
	//--------------------------------------------------- Render On Screen (Abstract)
	virtual void Render(bool Textured, bool Mapped, bool Lit) = 0;
	//--------------------------------------------------- Fill Buffers (Abstract)
	virtual void FillBuffers() = 0;
	//--------------------------------------------------- Return Model Matrix
	glm::mat4 GetMatrix();
	//--------------------------------------------------- Return Model Position
	glm::vec3 GetPosition();

protected:

	//--------------------------------------------------- Reset Object Matrix
	void Reset();
	//--------------------------------------------------- Buffers Attribute IDs
	static GLuint vertexAttributeID;
	static GLuint colorAttributeID;
	static GLuint normalAttributeID;
	static GLuint textureAttributeID;
	static GLuint tangentAttributeID;
	static GLuint bitangentAttributeID;
	//--------------------------------------------------- Light Attribute IDs
	static GLuint lightPositionUniformID;
	static GLuint lightAmbientUniformID;
	static GLuint lightDiffuseUniformID;
	static GLuint lightSpecularUniformID;
	//--------------------------------------------------- Material Attribute IDs
	static GLuint materialShininessUniformID;
	static GLuint materialAmbientUniformID;
	static GLuint materialDiffuseUniformID;
	static GLuint materialSpecularUniformID;
	//--------------------------------------------------- Texture Attribute IDs
	static GLuint textureNormals2UniformID;
	static GLuint textureNormalsUniformID;
	static GLuint textureDiffuseUniformID;
	static GLuint textureSpecularUniformID;
	//--------------------------------------------------- Checks Attribute IDs
	static GLuint textFlagUniformID;
	static GLuint mapFlagUniformID;
	static GLuint mapFlag2UniformID;
	static GLuint litFlagUniformID;
	//--------------------------------------------------- Matrix Attribute ID
	static GLuint modelUniformID;
	//--------------------------------------------------- Model Matrix
	glm::mat4 ModelMat;
	//--------------------------------------------------- Object Transformations
	glm::vec3 ObjectPos;
	glm::vec3 ObjectRot;
	glm::vec3 ObjectSca;
	//--------------------------------------------------- Floor Target
	glm::vec3 ObjectTarg;
	//--------------------------------------------------- Floor Tag
	std::string ObjectTag;
};

