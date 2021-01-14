#include <iostream>
#include "./Constants.h"
#include "./Game.h"
Game::Game()
{
	this->isRunning = false;
}

Game::~Game()
{}

bool Game::IsRunning() const
{
	return isRunning;
}
/** TMP code to test the loop **/

float projectilePosX = 0.0f;
float projectilePosY = 0.0f;
float projectileVelX = 0.1f;
float projectileVelY = 0.5f;
/*******************************/

void Game::Initialize(int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL failed to initialize\n";
		return;
	}

	window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			width,
			height,
			SDL_WINDOW_BORDERLESS
	);

	if (!window)
	{
		std::cerr << "Failed to create SDL window\n";
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer)
	{
		std::cerr << "Failed to create SDL renderer\n";
		return;
	}

	isRunning = true;
	return;
}


void Game::ProcessInput()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				isRunning = false;
			}
			break;
		default:
			break;
	}
}

void Game::Update()
{
	projectilePosX += projectileVelX;
	projectilePosY += projectileVelY;
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
}
void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
	SDL_RenderClear(renderer);
	SDL_Rect projectile {
		(int) projectilePosX,
		(int) projectilePosY,
		10,
		10
	};
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer,  &projectile);
	SDL_RenderPresent(renderer);
}
