#include "RunState.h"


RunState::RunState(GameStates* current) : GameStates(current)
{
	_isActive = _isAlive = true;

	
}


RunState::~RunState()
{


}

bool RunState::update(double dt)
{
	keys = Input::Instance()->GetKeyStates();  

	////read keyboard state
	return true;
}

bool RunState::Draw()
{
	return false;
}

float RunState::GetScore()
{
	return _score;
}