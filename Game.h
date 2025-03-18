#include<iostream>
#include<SDL.h>
#include"Movement.h"
#include"Tetrominoes.h"

class Game {
public:
	Game(int width, int heigth);
	void Run(); 
	~Game();
private:
	SDL_Window* window;
	SDL_Renderer* renderer; 
	Movement movement;
	Tetromino t;
	std::vector<std::vector<int>> grid;
	void Input();
	void Update();
	void Render();
	bool gameLoop = true;
};