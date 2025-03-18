#include"Game.h"
#include<vector>

Game::Game(int width, int heigth) : window(0), renderer(0) ,grid(heigth/50,std::vector<int>(width/50)),t(Type::O,5,0),movement(width/50,heigth/50,grid){
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
		if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.scancode) {
			case SDL_SCANCODE_LEFT:
				movement.moveLeft(t);
				break;
			case SDL_SCANCODE_RIGHT:
				movement.moveRight(t);
				break;
			case SDL_SCANCODE_DOWN:
				movement.moveDown(t);
				break;
			case SDL_SCANCODE_UP:
				movement.rotate(t);
				break;
			}
		}
	}
}

void Game::Update() {
	static int framework = 0;
	framework++;
	if (framework >= 30) {
		if (!movement.moveDown(t)) {
			for (int i = 0; i < t.shape.size(); i++) {
				for (int j = 0; j < t.shape[0].size(); j++) {
					if (t.shape[i][j] == 1)
						grid[t.y + i][t.x + j] = 1;
				}
			}
			t = Tetromino(static_cast<Type>(rand() % 7), 5, 0);
			if (movement.checkCollision(t, t.x, t.y)) {
				gameLoop = false;
				printf("Game Over\n");
			}
		}
		framework = 0;
	}
	for (int i = grid.size() - 1; i >= 0; i--) {
		bool line = true;
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 0) {
				line = false;
				break;
			}
		}
		if (line) {
			grid.erase(grid.begin() + i);
			grid.insert(grid.begin(), std::vector<int>(grid[0].size(), 0));
		}
	}
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == 1) {
				SDL_Rect block = { j * 50,i * 50,50,50 };
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderFillRect(renderer, &block);
			}
		}
	}
	t.draw(renderer);
	SDL_RenderPresent(renderer);
}