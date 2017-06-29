#pragma once
#include "GameStates.h"
#include "GameStates.h"
#include "RunState.h"
#include "FileManager.h"


class MainMenuState :
	public GameStates
{
public:
	MainMenuState(GameStates *current); //CLASS CREATED
	virtual ~MainMenuState();

private:
	
	
public:
	virtual bool update(double dt) ;
	virtual bool Draw() ;

};

