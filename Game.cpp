#include"Game.h"
#include<vector>

Game::Game(int width, int heigth) : window(0), renderer(0) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Cannnot initialize SDL: %s\n", SDL_GetError());
		gameLoop = false;
	}
	else {
		window = SDL_CreateWindow("TETRIS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, heigth, SDL_WINDOW_SHOWN);
		if (!window) {
			printf("Cannot create window: %s\n", SDL_GetError());
			gameLoop = false;
		}
		else {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (!renderer) {
				printf("Cannot create renderer: %s\n", SDL_GetError());
				gameLoop = false;
			}
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			SDL_RenderClear(renderer);
			std::vector<std::vector<int>> grid(heigth/50,std::vector<int>(width/50));
			for (int i = 0; i < grid.size(); i++) {
				for (int j = 0; j < grid[0].size(); j++) {
					SDL_Rect block = { j*50,i*50,50,50 };
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderDrawRect(renderer, &block);
				}
			}
			SDL_RenderPresent(renderer);
		}
	}
}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::Run() {
	while (gameLoop) {
		Input();
		Update();
		Render();  
	}
}

void Game::Input() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_Q) {
			gameLoop = false;
		}
	}
}

void Game::Update() {

}

void Game::Render() {
	SDL_RenderPresent(renderer);
}