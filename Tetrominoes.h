#pragma once

#include<iostream>
#include<SDL.h>
#include<vector>
#include<cstdlib>

enum class Type : uint8_t{
	O, I, T, L, J, S, Z
};

class Tetromino {
public:
	Type type;
	int x, y;
	std::vector<std::vector<int>> shape;
	Tetromino(Type t, int x , int y) : type(t) , x(x) , y(y){
		initialise();
	}
	void rotate();
	void draw(SDL_Renderer* renderer);
	void gravity();
private:
	void initialise() {
		switch (type) {
		case Type::O:
			shape = { {1,1} , {1,1} };
			break;
		case Type::I:  
			shape = { {1,1,1,1} };
			break;
		case Type::T:
			shape = { {0,1,0},{1,1,1} };
			break;
		case Type::L:
			shape = { {0,0,1},{1,1,1} };
			break;
		case Type::J:
			shape = { {1,0,0},{1,1,1} };
			break;
		case Type::S:
			shape = { {0,1,1},{1,1,0} };
			break;
		case Type::Z:
			shape = { {1,1,0},{0,1,1} };
			break;
		}
	}
};