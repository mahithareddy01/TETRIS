#include<iostream>
#include<SDL.h>

class Game {
public:
	Game(int width, int heigth);
	void Run(); 
	~Game();
private:
	SDL_Window* window;
	SDL_Renderer* renderer; 
	void Input();
	void Update();
	void Render();
	bool gameLoop = true;
};