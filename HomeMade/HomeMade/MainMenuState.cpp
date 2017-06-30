#include "MainMenuState.h"



MainMenuState::MainMenuState(GameStates* current) : GameStates(current)
{
	
	_isActive = _isAlive = true;

	_twodcam.Locate();

	_p->SetAttributes();
	_p->SetColors(glm::vec3(1), glm::vec3(1), glm::vec3(1));
	_p->FillBuffers();
	_p->InitShininess(1);
	_p->InitPosition(glm::vec3(0));
	_p->InitScale(glm::vec3(1));
	_p->InitRotation(glm::vec3(0));

}


MainMenuState::~MainMenuState()
{
	
}

bool MainMenuState::update(double dt)
{


	Screen::Instance()->ThreeDScreen(100, 1920, 1080);

	_twodcam.Update();

	

	_p->UpdateInputs();



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
	_p->Render(true, true, false);
	return false;
}

