#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <SDL2/SDL.h>
#include <string>

//TODO:map sdl keys to game commands as defined to config.lua

class InputManager
{
public:
	void HandleEvent();

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
