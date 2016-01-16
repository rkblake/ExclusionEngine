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

void CoreEngine::Start(const char* windowConfigPath) {
	/* Get the singleton instance of the RenderingEngine. */
	static RenderingEngine& renderer = RenderingEngine::GetInstance();
	static PhysicsEngine& physics = PhysicsEngine::GetInstance();

	/* Load window configuration. */
	Script config(windowConfigPath);
	//Script main("scripts/main.lua");
	CreateWindow(config);

	/* Initialize the RenderingEngine. */
	renderer.Init();

	m_pInputManager = new InputManager();
    
	/* testing purposes only. */
	demo(renderer, physics);
	
	Run();
}

void CoreEngine::Stop() {
	// TODO: cleanup
}

void CoreEngine::demo(RenderingEngine& renderer, PhysicsEngine& physics) {
	World* world = new World("scripts/world1.lua");
	Entity* sphere = new Entity("scripts/test_entity.lua");
	player = sphere;
	//Entity* cube = new Entity("scripts/cube.lua");
	//sphere->Renderable::translate(0, 10, 0);
	
	physics.SetWorld(world);
	renderer.SetWorld(world);
	//cube->translate(10,25,0);
	//RegisterEntity(cube);
	RegisterEntity(sphere);
	//Entity* null = GetNullEntity();
	//RenderingEngine::GetInstance().AttachEntity(sphere);
}

Entity* CoreEngine::GetNullEntity() {
	return new Entity(0);
}

void CoreEngine::Run() {
	bool isRunning = true;
	//SDL_Event e;
	const Uint8* keys;
	keys = SDL_GetKeyboardState(NULL);

	while(isRunning) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		PhysicsEngine::GetInstance().StepSimulation();
		//player->getController()->playerStep(PhysicsEngine::GetInstance().getWorld(), deltaTime);
		m_pInputManager->GetInputs();
		player->Update();
		RenderingEngine::GetInstance().RenderScene();
		window->SwapBuffers();
/* TODO: fix SDL_QUIT handling
		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
			}
		}
*/
		if(keys[SDL_SCANCODE_ESCAPE])
			isRunning = false;

	}
	Stop();
}

void CoreEngine::CreateWindow(Script config) {
	int width = (int)config.GetNumber("width");
	int height = (int)config.GetNumber("height");
	const char* title = config.GetString("title");
	window = RenderingEngine::GetInstance().CreateWindow(title, width, height);
}

void CoreEngine::RegisterEntity(Entity* entity) {
	RenderingEngine::GetInstance().RegisterEntity(entity);
	PhysicsEngine::GetInstance().RegisterEntity(entity);
}

InputManager* CoreEngine::GetInputManager() {
	return m_pInputManager;
}
