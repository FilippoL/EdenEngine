#include "Camera.h"
#include "ShaderManager.h"
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtx\rotate_vector.hpp>


Camera::Camera()
{

}

void Camera::Locate()
{
	shaderProgramID = Shade::Instance()->GetShaderID();
	viewUniform = glGetUniformLocation(shaderProgramID, "viewIn");
	projUniform = glGetUniformLocation(shaderProgramID, "worldIn");
	positionUniform =  glGetUniformLocation(shaderProgramID, "camera.Position");
}

void Camera::Draw()
{
	glUniformMatrix4fv(viewUniform, 1, GL_FALSE, &m_view[0][0]);
}

GLint Camera::GetPositionUniform()
{
	return positionUniform;
}

Camera::~Camera()
{


}
