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
		game->ProcessInput();

		int timeToWait = (SDL_GetTicks() - ticksLastTime) - FRAME_TARGET_TIME;

		if(timeToWait > 0 && timeToWait <= FRAME_TARGET_TIME)
		{
			SDL_Delay(timeToWait);
		}
		deltaTime = (SDL_GetTicks() - ticksLastTime) / 1000.0f;
		deltaTime = deltaTime > 0.05f ? 0.05f : deltaTime;
		ticksLastTime = SDL_GetTicks();
		game->Update(deltaTime);
		game->Render();
	}
	game->Destroy();
	delete game;
	return 0;
}
