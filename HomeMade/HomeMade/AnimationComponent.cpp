#include "AnimationComponent.h"

AnimationComponent::AnimationComponent()
{
	currentSet = "";
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::LoadAnimation(int SFrame, int EFrame, float DTSpeed, std::string AType)
{
	frameSet[AType].Start = SFrame;
	frameSet[AType].Frame = SFrame;
	frameSet[AType].End = EFrame;
	frameSet[AType].Speed = DTSpeed;
}

void AnimationComponent::Switch(std::string AType)
{
	if (currentSet != AType)
	{
		frameSet[currentSet].Frame = frameSet[currentSet].Start;
		currentSet = AType;
		frameSet[currentSet].Frame = frameSet[currentSet].Start;
	}
}

void AnimationComponent::Update(float DT)
{
	frameSet[currentSet].Frame += frameSet[currentSet].Speed*DT;
	if (frameSet[currentSet].Frame > frameSet[currentSet].End)
	{
		if (currentSet != "")
		{
			frameSet[currentSet].Frame = frameSet[currentSet].Start;
			currentSet = "";
			frameSet[currentSet].Frame = frameSet[currentSet].Start;
		}
	}
}

int AnimationComponent::Animate()
{
	return frameSet[currentSet].Frame;
}

std::string AnimationComponent::GetState()
{
	return currentSet;
}
