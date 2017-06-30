#include "ModelManager.h"

bool ModelManager::LoadAsset(std::string Identity)
{
	File::Instance()->SetSection(Identity);
	
	int temp_totFrame;
	temp_totFrame = int(File::Instance()->GetNumericVariable("total_frames"));

	for (int Frame = 0; Frame < temp_totFrame;Frame++)
	{
		std::string filepath = File::Instance()->GetAlphabeticVariable("path_to_obj") + std::to_string(Frame) + ".obj";

		//load model into assimp as a scene (nodes/meshes/faces/vertices/uvs/normals/indices)
		const aiScene* Scene = aiImportFile(filepath.c_str(), aiProcess_Triangulate |
			aiProcess_FixInfacingNormals |
			aiProcess_CalcTangentSpace |
			aiProcess_FlipUVs |
			aiProcess_FindInvalidData |
			aiProcess_OptimizeMeshes |
			aiProcess_OptimizeGraph |
			aiProcess_ValidateDataStructure);

		if (!Scene) { std::cout << "Mesh Loading Error->" << filepath << "->" << aiGetErrorString << std::endl << std::endl; return false; }
		else { std::cout << "Mesh Loaded->" << filepath << std::endl << std::endl; }

		Vertices.clear();
		Colors.clear();
		Normals.clear();
		TextureC.clear();
		Tangent.clear();
		BiTangent.clear();
		Indices.clear();

		TotalVerts[Identity][Frame] = 0;

		//mesh total vertices
		if (Scene->HasMeshes())
		{
			for (int Mesh = 0; Mesh < Scene->mNumMeshes; Mesh++)
			{
				TotalVerts[Identity][Frame] += Scene->mMeshes[Mesh]->mNumVertices;

				if (Scene->mMeshes[Mesh]->HasNormals() && Scene->mMeshes[Mesh]->HasTextureCoords(0) &&
					Scene->mMeshes[Mesh]->HasFaces() && Scene->mMeshes[Mesh]->HasTangentsAndBitangents())
				{
					for (int Vertex = 0; Vertex < Scene->mMeshes[Mesh]->mNumVertices; Vertex++)
					{
						//mesh vertices
						Vertices[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mVertices[Vertex].x);
						Vertices[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mVertices[Vertex].y);
						Vertices[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mVertices[Vertex].z);

						//mesh colors
						Colors[Identity][Frame].push_back(1.0f);
						Colors[Identity][Frame].push_back(1.0f);
						Colors[Identity][Frame].push_back(1.0f);

						//mesh normals
						Normals[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mNormals[Vertex].x);
						Normals[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mNormals[Vertex].y);
						Normals[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mNormals[Vertex].z);

						//mesh texture coords
						TextureC[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mTextureCoords[0][Vertex].x);
						TextureC[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mTextureCoords[0][Vertex].y);

						//mesh tangent
						Tangent[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mTangents[Vertex].x);
						Tangent[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mTangents[Vertex].y);
						Tangent[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mTangents[Vertex].z);

						//mesh bitangent
						BiTangent[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mBitangents[Vertex].x);
						BiTangent[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mBitangents[Vertex].y);
						BiTangent[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mBitangents[Vertex].z);

					}
					//mesh indices
					for (int Face = 0; Face < Scene->mMeshes[Mesh]->mNumFaces; Face++)
					{
						for (int Index = 0; Index < Scene->mMeshes[Mesh]->mFaces[Face].mNumIndices; Index++)
						{
							Indices[Identity][Frame].push_back(Scene->mMeshes[Mesh]->mFaces[Face].mIndices[Index]);
						}
					}
				}
			}
		}
		//release scene pointer
		aiReleaseImport(Scene);
	}

	return true;
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

	TotalVerts[Identity][0] = 36;

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
