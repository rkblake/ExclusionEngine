#include "CoreEngine.h"

CoreEngine::CoreEngine()
	//renderer(RenderingEngine::GetInstance()),
	//physics(PhysicsEngine::GetInstance()),
	//scripter(ScriptingEngine::GetInstance()),
	//input(InputManager::GetInstance())
{

}

CoreEngine::~CoreEngine()
{

}

void CoreEngine::CreateWindow(const char* title, int width, int height) {
	window = RenderingEngine::GetInstance().CreateWindow(title, width, height);
}

void CoreEngine::RegisterEntity(Entity* entity) {
	RenderingEngine::GetInstance().RegisterEntity(entity);
	PhysicsEngine::GetInstance().RegisterEntity(entity);
}

InputManager* CoreEngine::GetInputManager() {
	return m_pInputManager;
}

void CoreEngine::Start() {
	Script config("scripts/config.lua");
	//Script main("scripts/main.lua");
	int width = (int)config.GetNumber("width");
	int height = (int)config.GetNumber("height");
	const char* title = config.GetString("title");
	CreateWindow(title, width, height);
	RenderingEngine::GetInstance().Init();
	m_pInputManager = new InputManager();
	World* world = new World("scripts/world1.lua");
	Entity* sphere = new Entity("scripts/test_entity.lua");
	player = sphere;
	//Entity* cube = new Entity("scripts/cube.lua");
	//sphere->Renderable::translate(0, 10, 0);
	PhysicsEngine::GetInstance().SetWorld(world);
	RenderingEngine::GetInstance().SetWorld(world);
	//cube->translate(10,25,0);
	//RegisterEntity(cube);
	RegisterEntity(sphere);
	//Entity* null = GetNullEntity();
	RenderingEngine::GetInstance().AttachEntity(sphere);
	Run();
}

void CoreEngine::Stop() {
	//do cleanup
}

Entity* CoreEngine::GetNullEntity() {
	return new Entity(0);
}

void CoreEngine::Run() {
	bool isRunning = true;
	SDL_Event e;
	const Uint8* keys;
	keys = SDL_GetKeyboardState(NULL);

	while(isRunning) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		PhysicsEngine::GetInstance().StepSimulation();
		//player->getController()->playerStep(PhysicsEngine::GetInstance().getWorld(), deltaTime);
		RenderingEngine::GetInstance().RenderScene();
		window->SwapBuffers();

		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
			}
		}

		if(keys[SDL_SCANCODE_ESCAPE])
			isRunning = false;

	}
	Stop();
}
