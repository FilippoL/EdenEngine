#pragma once
#include <map>

struct FrameSet
{
	int Type;
	float Start;
	float End;
	float Speed;
	bool State;
	float Frame;
};

class AnimationComponent
{
public:
	AnimationComponent();
	~AnimationComponent();
	
	void LoadAnimation(int SFrame, int EFrame, float DTSpeed, std::string AType);
	void Switch(std::string AType);
	void Update(float DT);

	int Animate();
	std::string GetState();

private:

	std::map<std::string, FrameSet> frameSet;
	std::string currentSet;
	float DeltaTime;
};