#include"Movement.h"

Movement::Movement(int width,int height,std::vector<std::vector<int>>& grid)
	:width(width),height(height),grid(grid) { }

bool Movement::moveDown(Tetromino& t) {
	int newY = t.y + 1;
	if (!checkCollision(t, t.x, newY)) {
		t.y = newY;
		return true;
	}
	else {
		for (int i = 0; i < t.shape.size(); i++) {
			for (int j = 0; j < t.shape[i].size(); j++) {
				if (t.shape[i][j] == 1) {
					if (t.y + i >= 0 && t.y + i < height && t.x + j >= 0 && t.x + j < width) {
						grid[t.y + i][t.x + j] = 1;
					}
				}
			}
		}
		return false;
	}
}

void Movement::moveLeft(Tetromino& t) {
	int newX = t.x - 1;
	if (!checkCollision(t, newX, t.y)) {
		t.x = newX;
	}
}

void Movement::moveRight(Tetromino& t) {
	int newX = t.x + 1;
	if (!checkCollision(t, newX, t.y)) {
		t.x = newX;
	}
}

void Movement::rotate(Tetromino& t) {

}

bool Movement::checkCollision(const Tetromino& t, int newX, int newY) {
	for (int i = 0; i < t.shape.size(); i++) {
		for (int j = 0; j < t.shape[i].size(); j++) {
			if (t.shape[i][j] == 1) {
				if (newX + j < 0 || newX + j >= width || newY + i >= height || grid[newY + j][newX + i] == 1)
					return true;
			}
		}
	}
	return false;
}