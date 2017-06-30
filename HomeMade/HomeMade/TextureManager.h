#pragma once
#include <string>
#include "Singleton.h"
#include "FileManager.h"


#include <map>
#include <iostream>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <glew.h>
#include <windows.h>
#include <glm.hpp>
#include <glext.h>
#include <math.h>
#include <algorithm>

class TextureManager
{
public:
	friend class Singleton<TextureManager>;

public:

	GLuint GetDiffID(std::string name);

	GLuint GetSpecID(std::string name);

	GLuint GetNormID(std::string name);

	bool LoadFile(std::string name, bool repeated = false);
	void AddTexture(std::string, GLuint);
	void UnloadSingleFile(std::string ID);
	void UnloadFile();

private:
	TextureManager() {};
	TextureManager(const TextureManager&);
	TextureManager& operator=(const TextureManager&);

	std::map<std::string, GLuint>  m_TextureMap;



	~TextureManager();
};
typedef Singleton<TextureManager> Texture;