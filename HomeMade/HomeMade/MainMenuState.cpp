#include "MainMenuState.h"



MainMenuState::MainMenuState(GameStates* current) : GameStates(current)
{
	
	_isActive = _isAlive = true;

	

}


MainMenuState::~MainMenuState()
{
	
}

bool MainMenuState::update(double dt)
{
	

	//if ()
	//{
	//	TheGame::Instance()->ChangeState(new ArcadeMode(this)); 
	//	_isActive = false; 
	//	_isAlive = false;
	//	
	//
	//}


	//if ()
	//{
	//	TheGame::Instance()->AddTempState(new HighScoreState(this));
	//	_isActive = false; 
	//	_isAlive = false; 
	//}
	

	//if ()
	//{
	//	TheGame::Instance()->AddTempState(new InstructionState(this)); 
	//	_isActive = false; 
	//	_isAlive = false; 

	//}

	return false;
}

bool MainMenuState::Draw()
{

	return false;
}

