#include "GameObject.h"

GameObject::GameObject()
{
	std::cout << "Object Element->";
}

GameObject::~GameObject()
{
	std::cout << "Object Element->";
}

void GameObject::Reset()
{
	ModelMat = glm::mat4(1);
}

void GameObject::InitPosition(glm::vec3 Coords)
{
	ObjectPos = Coords;
}

void GameObject::InitRotation(glm::vec3 Rotations)
{
	ObjectRot = Rotations;
}

void GameObject::InitScale(glm::vec3 Scales)
{
	ObjectSca = Scales;
}

void GameObject::SetTarget(glm::vec3 Target)
{
	ObjectTarg = Target;
}

void GameObject::SetAttributes()
{
	vertexAttributeID	 = glGetAttribLocation(Shade::Instance()->GetShaderID(), "positionIn");
	colorAttributeID	 = glGetAttribLocation(Shade::Instance()->GetShaderID(), "colorIn");
	normalAttributeID    = glGetAttribLocation(Shade::Instance()->GetShaderID(), "normalIn");
	textureAttributeID	 = glGetAttribLocation(Shade::Instance()->GetShaderID(), "textureIn");
	tangentAttributeID   = glGetAttribLocation(Shade::Instance()->GetShaderID(), "tangentIn");
	bitangentAttributeID = glGetAttribLocation(Shade::Instance()->GetShaderID(), "bitangentIn");

	textFlagUniformID	= glGetUniformLocation(Shade::Instance()->GetShaderID(), "Textured");
	mapFlagUniformID	= glGetUniformLocation(Shade::Instance()->GetShaderID(), "Mapped");
	mapFlag2UniformID	= glGetUniformLocation(Shade::Instance()->GetShaderID(), "Mapped2");
	litFlagUniformID	= glGetUniformLocation(Shade::Instance()->GetShaderID(), "Lit");
	modelUniformID		= glGetUniformLocation(Shade::Instance()->GetShaderID(), "modelIn");

	lightPositionUniformID = glGetUniformLocation(Shade::Instance()->GetShaderID(), "light.Position");
	lightAmbientUniformID  = glGetUniformLocation(Shade::Instance()->GetShaderID(), "light.Ambient");
	lightDiffuseUniformID  = glGetUniformLocation(Shade::Instance()->GetShaderID(), "light.Diffuse");
	lightSpecularUniformID = glGetUniformLocation(Shade::Instance()->GetShaderID(), "light.Specular");

	materialShininessUniformID = glGetUniformLocation(Shade::Instance()->GetShaderID(), "material.Shininess");
	materialAmbientUniformID   = glGetUniformLocation(Shade::Instance()->GetShaderID(), "material.Ambient");
	materialDiffuseUniformID   = glGetUniformLocation(Shade::Instance()->GetShaderID(), "material.Diffuse");
	materialSpecularUniformID  = glGetUniformLocation(Shade::Instance()->GetShaderID(), "material.Specular");

	textureNormals2UniformID  = glGetUniformLocation(Shade::Instance()->GetShaderID(), "txtmap.Normals2");
	textureNormalsUniformID   = glGetUniformLocation(Shade::Instance()->GetShaderID(), "txtmap.Normals");
	textureDiffuseUniformID   = glGetUniformLocation(Shade::Instance()->GetShaderID(), "txtmap.Diffuse");
	textureSpecularUniformID  = glGetUniformLocation(Shade::Instance()->GetShaderID(), "txtmap.Specular");
}

void GameObject::UnSetAttributes()
{
	glDisableVertexAttribArray(bitangentAttributeID);
	glDisableVertexAttribArray(tangentAttributeID);
	glDisableVertexAttribArray(normalAttributeID);
	glDisableVertexAttribArray(textureAttributeID);
	glDisableVertexAttribArray(colorAttributeID);
	glDisableVertexAttribArray(vertexAttributeID);
}

glm::mat4 GameObject::GetMatrix()
{
	return ModelMat;
}

glm::vec3 GameObject::GetPosition()
{
	return ObjectPos;
}

GLuint GameObject::vertexAttributeID	= 0;
GLuint GameObject::colorAttributeID	   = 0;
GLuint GameObject::normalAttributeID    = 0;
GLuint GameObject::textureAttributeID   = 0;
GLuint GameObject::tangentAttributeID   = 0;
GLuint GameObject::bitangentAttributeID = 0;

GLuint GameObject::textFlagUniformID	   = 0;
GLuint GameObject::mapFlagUniformID	   = 0;
GLuint GameObject::mapFlag2UniformID	   = 0;
GLuint GameObject::litFlagUniformID	   = 0;
GLuint GameObject::modelUniformID	   = 0;

GLuint GameObject::lightPositionUniformID = 0;
GLuint GameObject::lightAmbientUniformID  = 0;
GLuint GameObject::lightDiffuseUniformID  = 0;
GLuint GameObject::lightSpecularUniformID = 0;

GLuint GameObject::materialShininessUniformID = 0;
GLuint GameObject::materialAmbientUniformID   = 0;
GLuint GameObject::materialDiffuseUniformID   = 0;
GLuint GameObject::materialSpecularUniformID  = 0;

GLuint GameObject::textureNormals2UniformID   = 0;
GLuint GameObject::textureNormalsUniformID   = 0;
GLuint GameObject::textureDiffuseUniformID   = 0;
GLuint GameObject::textureSpecularUniformID  = 0;