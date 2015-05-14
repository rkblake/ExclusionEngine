#ifndef EE_INPUTMANAGER_H
#define EE_INPUTMANAGER_H

#include "ExclusionEngine.h"

#include <map>
#include <SDL2/SDL.h>
#include <string>

class Engine;

//TODO:map sdl keys to game commands as defined to config.lua

class InputManager : public Engine
{
public:
	void HandleKey();

	static inline InputManager& GetInstance()
	{
		static InputManager sInputManager;
		return sInputManager;
	}
private:
	InputManager() {}
	~InputManager() {}

	std::map<SDL_Keycode, std::string> input_map;
	std::map<std::string, bool> input_press_map;
};

#endif
