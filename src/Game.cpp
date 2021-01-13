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
float projectileVelX = 50.0f;
float projectileVelY = 50.0f;

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
{}

void Game::Destroy()
{}
void Game::Render()
{}	
