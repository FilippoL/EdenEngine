#include "PauseState.h"
 



PauseState::PauseState(GameStates * current) : GameStates(current)
{
	_isActive = _isAlive = true;
	
	
	
	
}
 

PauseState::~PauseState()
{
	
}


bool PauseState::update(double dt)
{	
	keys = Input::Instance()->GetKeyStates();

	

	//if (/*To go back to a no temporary state from a temporar state*/)
	//{
	//	_StatePrevious->isActive() = true; //Reactivate the play state
	//	_StatePrevious->isAlive() = true;

	//	_isActive = false; //set itself as dead
	//	_isAlive = false;
	//}

	//if (/*To leave the game*/)
	//{
	//	_StatePrevious->isActive() = false;
	//	_StatePrevious->isAlive() = false;

	//	_isActive = false;
	//	_isAlive = false;
	//}

	//if (/**/)
	//{
	//	/*SET THEM ALL AS DEAD AND CHANGESTATE()*/
	//	_StatePrevious->isActive() = false; 
	//	_StatePrevious->isAlive() = false;

	//	_isActive = false;
	//	_isAlive = false;

	//}

	return false;
}


bool PauseState::Draw()
{


	return false;
}
