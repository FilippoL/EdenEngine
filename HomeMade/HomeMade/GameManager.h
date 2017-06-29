#pragma once
#include "Singleton.h"
#include "ScreenManager.h"
#include "ShaderManager.h"
#include "AudioManager.h"
#include "AudioComponent.h"
#include "TwoDCam.h"


#include <iostream>
#include <string>
#include <vector>
#include <glew.h>
#include <glm.hpp>
#include <fmod.hpp>
#include <iostream>
#include <deque>


class GameManager
{

public:

	friend class Singleton<GameManager>;

	bool Initialise(std::string GameName, int Width, int Height);
	void Run();
	//void AddTempState(Gamestates * my_state);
	//void ChangeState(Gamestates * my_state);
	//void DeleteState();
	void ShutDown() ;
	
	bool endGame = false;

private:
	double NOW, DeltaTime, LAST;

private:

	GameManager();
	GameManager(const GameManager&);
	TwoDCam _twodcam;

	GameManager& operator=(const GameManager&);

};

typedef Singleton<GameManager> Game;


