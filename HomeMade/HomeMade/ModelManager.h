#pragma once
#include <string>
#include "Singleton.h"
#include <postprocess.h>
#include <cimport.h>
#include <scene.h>
#include <glm.hpp>
#include <glew.h>
#include <vector>
#include <map>

typedef std::map<std::string, std::map<GLint, std::vector<GLfloat>>> MapStringIntVGLfloat;
typedef std::map<std::string, std::map<GLint, std::vector<GLuint>>> MapStringIntVGLuint;

class ModelManager
{
public:
	friend class Singleton<ModelManager>;

public:

	bool LoadAsset(std::string Identity, int totframes);
	void LoadPlaceHolder(std::string Identity, glm::vec3 Sizes);

	void Unload();

public:

	std::vector<GLfloat>& GetVertices(	std::string Object, int frame) { return Vertices[Object][frame]; };
	std::vector<GLfloat>& GetColors(	std::string Object, int frame) { return Colors[Object][frame]; };
	std::vector<GLfloat>& GetNormals(	std::string Object, int frame) { return Normals[Object][frame]; };
	std::vector<GLfloat>& GetTextureC(	std::string Object, int frame) { return TextureC[Object][frame]; };
	std::vector<GLfloat>& GetTangent(	std::string Object, int frame) { return Tangent[Object][frame]; };
	std::vector<GLfloat>& GetBiTangent(	std::string Object, int frame) { return BiTangent[Object][frame]; };
	std::vector<GLuint>&  GetIndices(	std::string Object, int frame) { return Indices[Object][frame]; };
	GLint& GetTotalVerts(std::string Object) { return TotalVerts[Object]; }

private:
	ModelManager();
	ModelManager(const ModelManager&);
	ModelManager& operator=(const ModelManager&);
	~ModelManager();

private:

	MapStringIntVGLfloat Vertices;
	MapStringIntVGLfloat Colors;
	MapStringIntVGLfloat Normals;
	MapStringIntVGLfloat TextureC;
	MapStringIntVGLfloat Tangent;
	MapStringIntVGLfloat BiTangent;
	MapStringIntVGLuint Indices;
	std::map<std::string, GLint> TotalVerts;
};

typedef Singleton<ModelManager> Model;
