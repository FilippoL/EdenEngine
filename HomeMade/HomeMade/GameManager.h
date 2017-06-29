#pragma once
#include "Singleton.h"
#include "ScreenManager.h"
#include "ShaderManager.h"
#include "AudioManager.h"
#include "AudioComponent.h"
#include "ModelManager.h"
#include "InputManager.h"
#include "GameStates.h"
#include "MainMenuState.h"


#include <iostream>
#include <string>
#include <vector>
#include <glew.h>
#include <glm.hpp>
#include <fmod.hpp>
#include <iostream>
#include <deque>
#include <SDL.h>



class GameManager
{

public:

	friend class Singleton<GameManager>;

	bool Initialise(std::string GameName, int Width, int Height);
	void Run();
	void AddTempState(GameStates * my_state);
	void ChangeState(GameStates * my_state);
	void DeleteState();
	void ShutDown() ;
	
	bool endGame = false;

private:
	double NOW, DeltaTime, LAST;

private:

	GameManager();
	GameManager(const GameManager&);

	const Uint8* keys = nullptr;

	std::deque <GameStates*> _states;

	GameManager& operator=(const GameManager&);

};

typedef Singleton<GameManager> Game;


