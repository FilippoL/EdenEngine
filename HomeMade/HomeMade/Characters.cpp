#include "Characters.h"
#include <SDL_image.h>

Characters::Characters()
{
	std::cout << "3D Object" << std::endl << std::endl;

	//create VAO, VBOs and EBO 
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VertexVBO);
	glGenBuffers(1, &ColorVBO);
	glGenBuffers(1, &NormalVBO);
	glGenBuffers(1, &TextureVBO);
	glGenBuffers(1, &TangentVBO);
	glGenBuffers(1, &BiTangentVBO);
	glGenBuffers(1, &EBO);

	ObjectTag = "PORCODIO";

	FillBuffers();
}

Characters::~Characters()
{
	std::cout << "3D Object->";

	//Delete Buffers
	glDeleteBuffers(1, &EBO);
	glDeleteBuffers(1, &BiTangentVBO);
	glDeleteBuffers(1, &TangentVBO);
	glDeleteBuffers(1, &TextureVBO);
	glDeleteBuffers(1, &NormalVBO);
	glDeleteBuffers(1, &ColorVBO);
	glDeleteBuffers(1, &VertexVBO);
	glDeleteVertexArrays(1, &VAO);
}

void Characters::InitShininess(GLfloat Shininess)
{
	ShininessMaterial = Shininess;
}

void Characters::SetColors(glm::vec3 Ambient, glm::vec3 Diffuse, glm::vec3 Specular)
{
	AmbientMaterial = Ambient;
	DiffuseMaterial = Diffuse;
	SpecularMaterial = Specular;
}

void Characters::Render(bool Textured, bool Mapped, bool Lit)
{
	//bind Transformations
	glUniformMatrix4fv(modelUniformID, 1, GL_FALSE, &ModelMat[0][0]);

	//flag if Textured
	if (Textured == true) { glUniform1i(textFlagUniformID, true);  }
	else				  { glUniform1i(textFlagUniformID, false); }

	//flag if Mapped
	if (Mapped == true)	  { glUniform1i(mapFlagUniformID, true);  }
	else				  { glUniform1i(mapFlagUniformID, false); }

	//flag if Mapped2
	glUniform1i(mapFlag2UniformID, false);

	//flag if Lit
	if (Lit == true) { glUniform1i(litFlagUniformID, true);  }
	else			 { glUniform1i(litFlagUniformID, false); }

	glUniform1f(materialShininessUniformID, ShininessMaterial);

	glUniform3fv(materialAmbientUniformID,  1, &AmbientMaterial.r);
	glUniform3fv(materialDiffuseUniformID,  1, &DiffuseMaterial.r);
	glUniform3fv(materialSpecularUniformID, 1, &SpecularMaterial.r);

	glUniform1i(textureDiffuseUniformID, 0);
	glUniform1i(textureSpecularUniformID, 1);
	glUniform1i(textureNormalsUniformID, 2);

	//bind Diffuse Map
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID(ObjectTag));

	//bind Specular Map	
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID(ObjectTag));
	
	//bind Normal Map	
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, Texture::Instance()->GetID(ObjectTag));
	
	//bind VAO and render 
	glBindVertexArray(VAO);

	glDrawElements(GL_TRIANGLES, Model::Instance()->GetTotalVerts(ObjectTag,0), GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
}

void Characters::UpdateInputs()
{
	Reset();

	ModelMat = glm::translate(ModelMat, ObjectPos);
	ModelMat = glm::rotate(ModelMat, glm::radians(ObjectRot.x), glm::vec3(1, 0, 0));
	ModelMat = glm::rotate(ModelMat, glm::radians(ObjectRot.y), glm::vec3(0, 1, 0));
	ModelMat = glm::rotate(ModelMat, glm::radians(ObjectRot.z), glm::vec3(0, 0, 1));
	if (ObjectSca != glm::vec3(0))
	{
		ModelMat = glm::scale(ModelMat, ObjectSca);
	}
}

void Characters::FillBuffers()
{
	//bind all VBOs and shader attributes together with VAO 
	glBindVertexArray(VAO);

	//fill and link vertex VBO     
	glBindBuffer(GL_ARRAY_BUFFER, VertexVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Model::Instance()->GetVertices(ObjectTag,0).size(), &Model::Instance()->GetVertices(ObjectTag,0)[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(vertexAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(vertexAttributeID);

	//fill and link color VBO     
	glBindBuffer(GL_ARRAY_BUFFER, ColorVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Model::Instance()->GetColors(ObjectTag,0).size(), &Model::Instance()->GetColors(ObjectTag,0)[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(colorAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorAttributeID);

	//fill and link color VBO     
	glBindBuffer(GL_ARRAY_BUFFER, NormalVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Model::Instance()->GetNormals(ObjectTag,0).size(), &Model::Instance()->GetNormals(ObjectTag,0)[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(normalAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(normalAttributeID);

	//fill and link texture VBO     
	glBindBuffer(GL_ARRAY_BUFFER, TextureVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Model::Instance()->GetTextureC(ObjectTag,0).size(), &Model::Instance()->GetTextureC(ObjectTag,0)[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(textureAttributeID, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(textureAttributeID);

	//fill and link color VBO     
	glBindBuffer(GL_ARRAY_BUFFER, TangentVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Model::Instance()->GetTangent(ObjectTag,0).size(), &Model::Instance()->GetTangent(ObjectTag,0)[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(tangentAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(tangentAttributeID);

	//fill and link texture VBO     
	glBindBuffer(GL_ARRAY_BUFFER, BiTangentVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*Model::Instance()->GetBiTangent(ObjectTag,0).size(), &Model::Instance()->GetBiTangent(ObjectTag,0)[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(bitangentAttributeID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(bitangentAttributeID);

	//fill EBO with indices      
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)*Model::Instance()->GetIndices(ObjectTag,0).size(), &Model::Instance()->GetIndices(ObjectTag,0)[0], GL_DYNAMIC_DRAW);

	//end the VAO binding
	glBindVertexArray(0);
}