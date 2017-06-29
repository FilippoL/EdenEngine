#include "GameManager.h"
#include "ModelManager.h"
#include <iostream>
#include <SDL.h>
#include <string>
#include <vector>
#include <glew.h>
#include <glm.hpp>




bool GameManager::Initialise(std::string GameName, int Width, int Height)
{
	if (!Screen::Instance()->Init(GameName, Width, Height, 3, 3, false, false)) //Create a gl context and window with assignable parameters
	{
		std::cout << "Screen not initialised" << std::endl;
		return false;
	}


	Shade::Instance()->CreateProgram();
	Shade::Instance()->CreateShaders();
	
	Shade::Instance()->AttachShaders();
	
	if (!Shade::Instance()->CompileShaders("Main.vert"))
	{
		std::cout << "Shader not initialised" << std::endl;
		return false;
	}	
	
	if (!Shade::Instance()->CompileShaders("Main.frag")) 
	{
		std::cout << "Shader not initialised" << std::endl;
		return false;
	}

	Shade::Instance()->LinkProgram();

	Audio::Instance()->Init();

	Audio::Instance()->LoadMusic("soundtrack.mp3");


	_twodcam.Locate();

	//To add Object Manager and Texture Manager

	Model::Instance()->LoadPlaceHolder("BOX", glm::vec3(10.0f,10.0f,10.0f));	//Texture::Instance()->LoadTexture("Filepath");

	//m_Gstates.push_back(new MainMenuState(nullptr));

	std::cout << "Initialisation of Game succeded" << std::endl;

	return true;

}
 
void GameManager::Run()
{
	
		while (!endGame) //GAME LOOP
		{

			NOW = SDL_GetTicks();
			Screen::Instance()->clearScreen();

			Screen::Instance()->ThreeDScreen(100, 1920, 1080);
			
			_twodcam.Update();


			_twodcam.Draw();
			
			

			Screen::Instance()->SwapBuffer();
			
			LAST = SDL_GetTicks();
			DeltaTime = (LAST - NOW) / 1000;
			LAST = NOW = 0;

		}

}

//
//void GameManager::AddTempState(Gamestates * my_state)
//{
//	m_Gstates.push_front(my_state);
//}
//
//void GameManager::ChangeState(Gamestates * my_state)
//{
//	m_Gstates.push_back(my_state);
//
//	m_Gstates.front()->isActive() = false;
//	m_Gstates.front()->isAlive() = false;
//}
//
//void GameManager::DeleteState()
//{
//	delete m_Gstates.front();
//	m_Gstates.pop_front();
//}


void GameManager::ShutDown()
{
	
	Shade::Instance()->DetachDestroy();
	Screen::Instance()->ShutDown();
	Audio::Instance()->Unload();
	Audio::Instance()->ShutDown();

}


GameManager::GameManager()
{
}


