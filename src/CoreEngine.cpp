#include "CoreEngine.h"

const double FPS = 1.0/60.0;

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

void CoreEngine::Start() {
	Script config("scripts/config.lua");
	//Script main("scripts/main.lua");
	int width = (int)config.GetNumber("width");
	int height = (int)config.GetNumber("height");
	const char* title = config.GetString("title");
	CreateWindow(title, width, height);
	RenderingEngine::GetInstance().Init();
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
	double lastTime = SDL_GetTicks();
	double deltaTime, currentTime;

	while(isRunning) {
		currentTime = SDL_GetTicks();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;
		if(deltaTime > FPS)
			deltaTime = FPS;

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

		/*
		switch ((unsigned int)keys) {
			case SDL_SCANCODE_ESCAPE:
				isRunning = false;
				break;
			case SDL_SCANCODE_W:
				player->getController()->setVelocityForTimeInterval(btVector3(0,0,-1), 100);
				player->getController()->setWalkDirection(btVector3(0,0,-1));
		}
		*/

		if(keys[SDL_SCANCODE_ESCAPE])
			isRunning = false;
		if(keys[SDL_SCANCODE_W])
			player->setVelocity(0,1,0);
		if(keys[SDL_SCANCODE_A])
			player->setVelocity(-1,0,0);
		if(keys[SDL_SCANCODE_S])
			player->setVelocity(0,-1,0);
		if(keys[SDL_SCANCODE_D])
			player->setVelocity(1,0,0);


		if(deltaTime - FPS > 0)
			SDL_Delay(deltaTime - FPS);
	}
	Stop();
}
