#include "InputManager.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "Window.h"

SDL_Window* g_window;
unsigned int windowWidth, windowHeight;

InputManager::InputManager()
    : m_pWindow(NULL), m_quit(false),
    m_lmbDown(false), m_rmbDown(false),
    m_lmbClicked(false), m_rmbClicked(false)
{
    //m_pWindow = CoreEngine::GetInstance().GetWindow();
    // Get the number of keys
	SDL_GetKeyboardState(&m_numKeys);
	m_keyStateArraySizeBytes = m_numKeys * sizeof(Uint8);
	m_pPastKeyStates = new Uint8[m_numKeys];
	m_pCurrentKeyStates = new Uint8[m_numKeys];

	// Default to all false
	memset(m_pPastKeyStates, 0, m_keyStateArraySizeBytes);
	memset(m_pCurrentKeyStates, 0, m_keyStateArraySizeBytes);
}

InputManager::~InputManager() {
    delete m_pPastKeyStates;
	delete m_pCurrentKeyStates;
}

void InputManager::GetInputs() {
    //m_pWindow = CoreEngine::GetInstance().GetWindow();
    SDL_Event sdlEvent;

	m_lmbClicked = false;
	m_rmbClicked = false;

    //memcpy(m_pPastKeyStates, m_pCurrentKeyStates, m_keyStateArraySizeBytes);

	while(SDL_PollEvent(&sdlEvent))
	{
		switch(sdlEvent.type)
		{
		case SDL_QUIT:
			m_quit = true;
			break;

		case SDL_MOUSEMOTION:
			m_mouseX = sdlEvent.motion.x;

			if(m_pWindow == NULL)
				m_mouseY = sdlEvent.motion.y;
			else
				m_mouseY = windowHeight - sdlEvent.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			if(sdlEvent.button.button == SDL_BUTTON_LEFT)
			{
				if(!m_lmbDown)
					m_lmbClicked = true;

				m_lmbDown = true;
			}
			else if(sdlEvent.button.button == SDL_BUTTON_RIGHT)
			{
				if(!m_rmbDown)
					m_rmbClicked = true;

				m_rmbDown = true;
			}

			break;

		case SDL_MOUSEBUTTONUP:
			if(sdlEvent.button.button == SDL_BUTTON_LEFT)
				m_lmbDown = false;
			else if(sdlEvent.button.button == SDL_BUTTON_RIGHT)
				m_rmbDown = false;

			break;

        case SDL_KEYDOWN:
            //m_pCurrentKeyStates[sdlEvent.key.keysym.scancode] = 1;
            break;

        case SDL_KEYUP:
            //m_pCurrentKeyStates[sdlEvent.key.keysym.scancode] = 0;
            //m_pPastKeyStates[sdlEvent.key.keysym.scancode] = 1;
            break;

		}
	}

	// Copy states to past state buffer
	memcpy(m_pPastKeyStates, m_pCurrentKeyStates, m_keyStateArraySizeBytes);

	// Get key states
	const Uint8* pStates = SDL_GetKeyboardState(NULL);


	// Copy new states
	memcpy(m_pCurrentKeyStates, pStates, m_keyStateArraySizeBytes);
}

bool InputManager::Quit() {
    return m_quit;
}

bool InputManager::LMBDown() {
    return m_lmbDown;
}

bool InputManager::RMBDown() {
    return m_rmbDown;
}

bool InputManager::LMBClicked() {
    return m_lmbClicked;
}

bool InputManager::RMBClicked() {
    return m_rmbClicked;
}

unsigned int InputManager::GetMouseX() {
    return m_mouseX;
}

unsigned int InputManager::GetMouseY() {
    return m_mouseY;
}

Uint8 InputManager::GetCurrentKeyState(Uint8 key) {
    return m_pCurrentKeyStates[key];
}

Uint8 InputManager::GetCurrentKeyState(SDL_Keycode key) {
    return m_pCurrentKeyStates[key];
}

Uint8 InputManager::GetPastKeyState(Uint8 key) {
    return m_pPastKeyStates[key];
}

Uint8 InputManager::GetPastKeyState(SDL_Keycode key) {
    return m_pPastKeyStates[key];
}

bool InputManager::KeyPressed(Uint8 key) {
    return !m_pPastKeyStates[key] && m_pCurrentKeyStates[key];
}

bool InputManager::KeyPressed(SDL_Keycode key) {
    return !m_pPastKeyStates[key] && m_pCurrentKeyStates[key];
}

bool InputManager::KeyReleased(Uint8 key) {
    return m_pPastKeyStates[key] && !m_pCurrentKeyStates[key];
}

bool InputManager::KeyReleased(SDL_Keycode key) {
    return m_pPastKeyStates[key] && !m_pCurrentKeyStates[key];
}

void InputManager::SetMousePos(unsigned int x, unsigned int y) {
    SDL_WarpMouseInWindow(g_window, x, y);
}

void InputManager::KeepMouseInWindow(bool keepInWindow) {
    if(keepInWindow)
        SDL_SetWindowGrab(g_window, SDL_TRUE);
    else
        SDL_SetWindowGrab(g_window, SDL_FALSE);
}

void InputManager::ShowMouse(bool show) {
    SDL_ShowCursor(show);
}
