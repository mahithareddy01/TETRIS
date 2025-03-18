#pragma once

#ifndef MOVEMENT_H_
#define MOVEMENT_H_

#include"Tetrominoes.h"
#include<vector>

class Movement {
public:
	Movement(int width, int height, std::vector<std::vector<int>>& grid);

	void moveDown(Tetromino& t);
	void moveLeft(Tetromino& t);
	void moveRight(Tetromino& t);
	void rotate(Tetromino& t);
	bool checkCollision(const Tetromino& t, int newX, int newY);

private:
	int width, height;
	std::vector<std::vector<int>> grid;
};

#endif // !MOVEMENT_H_
