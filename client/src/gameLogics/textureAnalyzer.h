#pragma once
#include "types.h"

class TextureAnalyzer
{
public:
	TextureAnalyzer();
	Textures shipDamagedTexture(int i, int shipSize, bool orientation);
	Textures shipTexture(int i, int shipSize, bool orientation);
};

