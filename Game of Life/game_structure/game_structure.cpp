#include "game_structure.h"
#include "../vector2d/vector2d.h"

void Unit::change_state(void) {
	switch(state){
		case DEAD : state = ALIVE;
		break; 
		case ALIVE : state = DEAD;
		break;
	}
} 

void Game_Board::initialise(void){
	Vector2D initial_position(-0.5*game::BOARD_SIZE*game::UNIT_SIZE, -0.5*game::BOARD_SIZE*game::UNIT_SIZE);
	for (unsigned int i(0); i < game::BOARD_SIZE; ++i){
		for (unsigned int j(0); j < game::BOARD_SIZE; ++j){
			Vector2D new_position(initial_position[0]+i*game::UNIT_SIZE, initial_position[1]+j*game::UNIT_SIZE);
			board[i][j] = new Unit(support, new_position, DEAD);
		}
	}
}

void Game_Board::drawLine(size_t size, size_t line, size_t col_beg){
	for (size_t i(0); i < size; ++i){
		board[line][col_beg+i]->change_state();
	}
}

void Game_Board::drawCol(size_t size, size_t line_beg, size_t col){
	for (size_t i(0); i < size; ++i){
		board[line_beg+i][col]->change_state();
	}
}


void Game_Board::drawDiag(size_t size, size_t line_beg, size_t col_beg){
	for (size_t i(0); i < size; ++i){
		board[line_beg+i][col_beg+i]->change_state();
	}
}
