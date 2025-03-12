#include"Tetrominoes.h"
#include<chrono>

void Tetromino::rotate() {
	int row = shape.size();
	int col = shape[0].size();
	std::vector<std::vector<int>> res(col, std::vector<int>(row));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			res[j][row - i - 1] = shape[i][j];
		}
	}
	shape = res;
}

void Tetromino::draw(SDL_Renderer* renderer) {
	for (int i = 0; i < this->shape.size(); i++) {
		for (int j = 0; j < this->shape[0].size(); j++) {  
			if (this->shape[i][j] == 1) {
				SDL_Rect block = { (j + x) * 50,(i + y) * 50,50,50 };
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &block);
			}
		}
	}
}

void Tetromino::gravity() {
	 
}