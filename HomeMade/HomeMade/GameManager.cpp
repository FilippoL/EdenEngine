#include "GameManager.h"

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

	_states.push_back(new MainMenuState(nullptr));

	std::cout << "Initialisation of Game succeded" << std::endl;

	return true;

}
 
void GameManager::Run()
{
		while (!endGame) //GAME LOOP
		{
			if (_states.front()->isAlive() && _states.front()->isActive())
			{

			NOW = SDL_GetTicks();
			Screen::Instance()->clearScreen();

			Screen::Instance()->ThreeDScreen(100, 1920, 1080);
			
			Input::Instance()->Update();
			
			_twodcam.Update();


			_twodcam.Draw();
			
			

			

			
			
			(Input::Instance()->IsXClicked()) ? endGame = true : 0;
			
			Screen::Instance()->SwapBuffer();
			
			LAST = SDL_GetTicks();
			DeltaTime = (LAST - NOW) / 1000;

			LAST = NOW = 0;

		}

}

void GameManager::ChangeState(GameStates * my_state)
{
	_states.push_back(my_state);

	_states.front()->isActive() = false;
	_states.front()->isAlive() = false;
}

void GameManager::DeleteState()
{
	delete _states.front();
	_states.pop_front();
}


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


