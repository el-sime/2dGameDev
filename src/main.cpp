#include "./Constants.h"
#include "./Game.h"


int main(int argc, char *argv[])
{
	Game *game = new Game();

	game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);
	float deltaTime = 0.0f;
	float ticksLastTime = SDL_GetTicks();
	while(game->IsRunning())
	{
		deltaTime = (SDL_GetTicks() - ticksLastTime) / 1000;
		ticksLastTime = SDL_GetTicks();
		game->ProcessInput();
		game->Update(deltaTime);
		game->Render();
	}
	
	game->Destroy();

	delete game;

	return 0;
}
