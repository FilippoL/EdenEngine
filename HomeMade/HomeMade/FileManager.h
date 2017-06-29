#pragma once
#include <map>
#include <fstream>
#include "Singleton.h"


class FileManager
{
	friend class Singleton<FileManager>;

public:
	FileManager();

	void SetSection(std::string sec);
	
	std::string GetAlphabeticVariable(const std::string &VarName);

	float GetNumericVariable(std::string VarName);
	
	void OpenNewFile(std::string filename_with_no_extension);

	void ReadFromFile();

	void RemoveSpaces(std::string & givemeastring);

	std::string filename;

	std::fstream file;


	std::map<std::string, std::string> _variables_map;


	std::string _section;

};

typedef Singleton<FileManager> File;
