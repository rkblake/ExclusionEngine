#ifndef EE_INPUTMANAGER_H
#define EE_INPUTMANAGER_H

#include <SDL2/SDL.h>

#include "Window.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void GetInputs();
	bool Quit();
	bool LMBDown();
	bool RMBDown();
	bool LMBClicked();
	bool RMBClicked();

	Uint8 GetCurrentKeyState(Uint8 key);
	Uint8 GetCurrentKeyState(SDL_Keycode key);
	Uint8 GetPastKeyState(Uint8 key);
	Uint8 GetPastKeyState(SDL_Keycode key);

	bool KeyPressed(Uint8 key);
	bool KeyPressed(SDL_Keycode key);
	bool KeyReleased(Uint8 key);
	bool KeyReleased(SDL_Keycode key);

	unsigned int GetMouseX();
	unsigned int GetMouseY();

	static void SetMousePos(unsigned int x, unsigned int y);
	static void KeepMouseInWindow(bool keepInWindow);
	static void ShowMouse(bool show);
private:
	Window* m_pWindow;

	unsigned int m_mouseX, m_mouseY;
	bool m_quit;
	bool m_lmbDown, m_rmbDown;
	bool m_lmbClicked, m_rmbClicked;
	Uint8* m_pPastKeyStates;
	Uint8* m_pCurrentKeyStates;
	int m_numKeys;
	int m_keyStateArraySizeBytes;
};

#endif
