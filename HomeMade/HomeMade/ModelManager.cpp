#include "ModelManager.h"

bool ModelManager::LoadAsset(std::string Identity, int totframes)
{
	
	return false;
}

void ModelManager::LoadPlaceHolder(std::string Identity, glm::vec3 Sizes)
{
	Vertices.clear();
	Colors.clear();
	Normals.clear();
	TextureC.clear();
	Tangent.clear();
	BiTangent.clear();
	Indices.clear();

	TotalVerts[Identity] = 36;

	//mesh vertices
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2); //Front
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);

	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2); //Back
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);

	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2); //Left
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);

	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2); //Right
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);

	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2); //Top
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(+Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);

	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2); //Bottom
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(-Sizes.z / 2);
	Vertices[Identity][0].push_back(-Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);
	Vertices[Identity][0].push_back(+Sizes.x / 2);Vertices[Identity][0].push_back(-Sizes.y / 2);Vertices[Identity][0].push_back(+Sizes.z / 2);

	//mesh colors
	for (int VertexColor = 0; VertexColor < 24; VertexColor++)
	{
		Colors[Identity][0].push_back(1.0f);
		Colors[Identity][0].push_back(1.0f);
		Colors[Identity][0].push_back(1.0f);
	}

	//mesh normals
	for (int VertexNormal = 0; VertexNormal < 4; VertexNormal++)
	{
		Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(1.0f);	//Front
	}
	for (int VertexNormal = 0; VertexNormal < 4; VertexNormal++)
	{
		Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(-1.0f);	//Back
	}
	for (int VertexNormal = 0; VertexNormal < 4; VertexNormal++)
	{
		Normals[Identity][0].push_back(-1.0f);Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(0.0f);	//Left
	}
	for (int VertexNormal = 0; VertexNormal < 4; VertexNormal++)
	{
		Normals[Identity][0].push_back(1.0f);Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(0.0f);	//Right
	}
	for (int VertexNormal = 0; VertexNormal < 4; VertexNormal++)
	{
		Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(1.0f);Normals[Identity][0].push_back(0.0f);	//Top
	}
	for (int VertexNormal = 0; VertexNormal < 4; VertexNormal++)
	{
		Normals[Identity][0].push_back(0.0f);Normals[Identity][0].push_back(-1.0f);Normals[Identity][0].push_back(0.0f);	//Bottom
	}

	//mesh texture
	for (int VertexTexture = 0; VertexTexture < 6; VertexTexture++)
	{
		TextureC[Identity][0].push_back(0.0);
		TextureC[Identity][0].push_back(1.0);

		TextureC[Identity][0].push_back(0.0);
		TextureC[Identity][0].push_back(0.0);

		TextureC[Identity][0].push_back(1.0);
		TextureC[Identity][0].push_back(0.0);

		TextureC[Identity][0].push_back(1.0);
		TextureC[Identity][0].push_back(1.0);
	}

	//mesh tangents
	for (int VertexTangent = 0; VertexTangent < 4; VertexTangent++)
	{
		Tangent[Identity][0].push_back(1.0f);Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(0.0f);	//Front
	}
	for (int VertexTangent = 0; VertexTangent < 4; VertexTangent++)
	{
		Tangent[Identity][0].push_back(-1.0f);Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(0.0f);	//Back
	}
	for (int VertexTangent = 0; VertexTangent < 4; VertexTangent++)
	{
		Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(1.0f);	//Left
	}
	for (int VertexTangent = 0; VertexTangent < 4; VertexTangent++)
	{
		Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(-1.0f);	//Right
	}
	for (int VertexTangent = 0; VertexTangent < 4; VertexTangent++)
	{
		Tangent[Identity][0].push_back(1.0f);Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(0.0f);	//Top
	}
	for (int VertexTangent = 0; VertexTangent < 4; VertexTangent++)
	{
		Tangent[Identity][0].push_back(-0.0f);Tangent[Identity][0].push_back(0.0f);Tangent[Identity][0].push_back(0.0f);	//Bottom
	}

	//mesh tangents
	for (int VertexBiTangent = 0; VertexBiTangent < 4; VertexBiTangent++)
	{
		BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(1.0f);BiTangent[Identity][0].push_back(0.0f);	//Front
	}
	for (int VertexBiTangent = 0; VertexBiTangent < 4; VertexBiTangent++)
	{
		BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(1.0f);BiTangent[Identity][0].push_back(0.0f);	//Back
	}
	for (int VertexBiTangent = 0; VertexBiTangent < 4; VertexBiTangent++)
	{
		BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(1.0f);BiTangent[Identity][0].push_back(0.0f);	//Left
	}
	for (int VertexBiTangent = 0; VertexBiTangent < 4; VertexBiTangent++)
	{
		BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(1.0f);BiTangent[Identity][0].push_back(0.0f);	//Right
	}
	for (int VertexBiTangent = 0; VertexBiTangent < 4; VertexBiTangent++)
	{
		BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(-1.0f);	//Top
	}
	for (int VertexBiTangent = 0; VertexBiTangent < 4; VertexBiTangent++)
	{
		BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(0.0f);BiTangent[Identity][0].push_back(1.0f);	//Bottom
	}

	//mesh index
	for (int Face = 0; Face < 6; Face++)
	{
		Indices[Identity][0].push_back(0 + (Face * 4));
		Indices[Identity][0].push_back(1 + (Face * 4));
		Indices[Identity][0].push_back(3 + (Face * 4));

		Indices[Identity][0].push_back(1 + (Face * 4));
		Indices[Identity][0].push_back(2 + (Face * 4));
		Indices[Identity][0].push_back(3 + (Face * 4));
	}
}

void ModelManager::Unload()
{
}

ModelManager::ModelManager()
{
}

ModelManager::~ModelManager()
{
}
