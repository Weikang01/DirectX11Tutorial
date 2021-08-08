#pragma once
#include "Window.h"
#include "Timer.h"

class App
{
public:
	App();
	int run();
private:
	void DoFrame();
private:
	Window wnd;
	Timer timer;
};
