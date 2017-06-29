#include "GameManager.h"




bool GameManager::Initialise(std::string GameName, int Width, int Height)
{
	if (!Screen::Instance()->Init(GameName, Width, Height, 3, 3, false, false)) //Create a gl context and window with assignable parameters
	{
		std::cout << "Screen not initialised" << std::endl;
		return false;
	}

	File::Instance()->OpenNewFile("Settings");

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

			Input::Instance()->Update();

			keys = Input::Instance()->GetKeyStates();



			_states.front()->update(DeltaTime);

			_states.front()->Draw();




			if (Input::Instance()->IsXClicked())
			{	
				for (size_t s = 0; s < _states.size(); s++)
				{

					_states[s]->isActive() = false;
					_states[s]->isAlive() = false;
				}
			}

			//if escape key is pressed flag game to end
			if (keys[SDL_SCANCODE_ESCAPE])
			{
				for (size_t s = 0; s < _states.size(); s++)
				{
					_states[s]->isActive() = false;
					_states[s]->isAlive() = false;
				}
			}

			//draw screen by swapping frame buffer
			Screen::Instance()->SwapBuffer();

		}

		if (!_states.front()->isAlive())
		{
			DeleteState();
		}


		if (_states.empty()) //if everything is deleted exit
		{
			endGame = true;
		}


		std::cout << DeltaTime << std::endl;
		system("cls");

		LAST = SDL_GetTicks();
		DeltaTime = (LAST - NOW) / 1000;

		LAST = NOW = 0;
	}

}


void GameManager::AddTempState(GameStates * my_state)
{
	_states.push_front(my_state);
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


