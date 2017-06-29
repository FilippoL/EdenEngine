#pragma once
#include "GameStates.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "TextureManager.h"
#include "ScreenManager.h"
#include "GameStates.h"
#include "MainMenuState.h"


class PauseState :
	public GameStates  
{
public:
	PauseState(GameStates* current);
	virtual ~PauseState();

public:
	virtual bool update(double dt);
	virtual bool Draw();

public:
	const Uint8* keys = nullptr;
};

