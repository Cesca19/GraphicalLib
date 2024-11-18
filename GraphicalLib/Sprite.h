#pragma once
#include <string>

class Sprite {

public:
	virtual void LoadImage(std::string filePath) = 0;
	virtual void Render() = 0;

};

