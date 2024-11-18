#pragma once
#include "string"

class Window {

public:
	Window();
	~Window();
	virtual void Init() = 0;
	virtual void CreateWindow() = 0;
	virtual void IsWindowOpen() = 0;

};

