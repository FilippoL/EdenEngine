#include "MainMenuState.h"



MainMenuState::MainMenuState(GameStates* current) : GameStates(current)
{
	
	_isActive = _isAlive = true;

	_twodcam.Locate();


}


MainMenuState::~MainMenuState()
{
	
}

bool MainMenuState::update(double dt)
{
	Screen::Instance()->ThreeDScreen(100, 1920, 1080);

	_twodcam.Update();

	File::Instance()->SetSection("PORCODIO");

	std::cout << File::Instance()->GetAlphabeticVariable("PATH") << std::endl;
	std::cout << File::Instance()->GetNumericVariable("FRAME") << std::endl;

	//if ()
	//{
	//	TheGame::Instance()->ChangeState(new ArcadeMode(this)); 
	//	_isActive = false; 
	//	_isAlive = false;
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
	_twodcam.Draw();

	return false;
}

