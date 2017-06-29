#pragma once
#include "AudioManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "ScreenManager.h"
#include "MainMenuState.h"
#include "GameStates.h"

#include <SDL.h> 
#include <iostream>
#include <string>


class RunState :
	public GameStates
{
public:
	RunState(GameStates * current);
	virtual ~RunState();


public:

	virtual bool update(double dt);
	virtual bool Draw();

	float GetScore();


};

