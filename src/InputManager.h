#ifndef EE_INPUTMANAGER_H
#define EE_INPUTMANAGER_H

//#include "Engine.h"

#include <map>
//#include <pair>
#include <SDL2/SDL.h>
#include <string>

class Engine;

typedef union {
	SDL_Keycode keycode; //Uint8
	SDL_Scancode scancode; //Uint8
	Sint32 mouse_button;
} Button;

enum CommandsEnum {
	FORARD,
	BACKWARD,
	LEFT_STRAFE,
	RIGHT_STRAFE,
	FIRE,
	RELOAD
};

const std::string Commands[] = {
	"FORWARD",
	"BACKWARD",
	"LEFT_STRAFE",
	"RIGHT_STRAFE",
	"JUMP",
	"FIRE",
	"RELOAD",
	"\0"
};

typedef std::pair<Button, std::string*> map_item;
typedef std::pair<std::string*, bool> press_map_item;

class InputManager
{
public:
	static inline InputManager& GetInstance() {
		static InputManager sInputManager;
		return sInputManager;
	}

	void init();
private:
	InputManager() {}
	~InputManager() {}

	std::map<Button, std::string*> input_map;
	std::map<std::string*, bool> input_press_map;
};

#endif
