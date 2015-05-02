#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "ExclusionEngine.h"

#include <map>
#include <SDL2/SDL.h>
#include <string>

class Engine;

//TODO:map sdl keys to game commands as defined to config.lua

class InputManager : public Engine
{
public:
	void HandleEvent();

	static inline InputManager* GetInstance()
	{
		static InputManager sInputManager;
		InputManager* input = &sInputManager;
		return input;
	}
private:
	InputManager() {}
	~InputManager() {}

	std::map<SDL_Keycode, std::string> input_map;
	std::map<std::string, bool> input_press_map;
};

#endif
