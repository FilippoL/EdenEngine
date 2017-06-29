#pragma once
#include "GameStates.h"
#include "GameStates.h"
#include "RunState.h"
#include "FileManager.h"
#include "TwoDCam.h"
#include "ModelManager.h"


class MainMenuState :
	public GameStates
{
public:
	MainMenuState(GameStates *current); //CLASS CREATED
	virtual ~MainMenuState();

public:
	virtual bool update(double dt) ;
	virtual bool Draw();
	TwoDCam _twodcam;

};

