#include "game_structure.h"
#include "../vector2d/vector2d.h"

void Unit::change_state(State my_state) {
	state = my_state;
} 

void Unit::die(void) {
	state = states::DEAD;
}

void Unit::live(void) {
	state = states::ALIVE;
}

void Line::initialise(unsigned short int y_pos){
	for (unsigned short int i(0); i < game::BOARD_SIZE; ++i){
		Vector2D new_position(i*game::UNIT_SIZE, y_pos);
		line.push_back(new Unit(support, new_position, states::DEAD));
	}
}

void Game_Board::initialise(void){
	board.reserve(game::BOARD_SIZE);
	for (unsigned short int i(0); i < game::BOARD_SIZE; ++i){
		std::vector<Unit*> line;
		line.reserve(game::BOARD_SIZE);
		for (unsigned short int j(0); j < game::BOARD_SIZE; ++j){
			Vector2D new_position(i*game::UNIT_SIZE, j*game::UNIT_SIZE);
			line.push_back(new Unit(support, new_position, states::DEAD));
		}
		board.push_back(line);
	}
}

void Game_Board::drawLine(unsigned short int size, unsigned short int line, unsigned short int col_beg){
	for (unsigned short int i(0); i < size; ++i){
		board[line][col_beg+i]->live();
	}
}

void Game_Board::drawCol(unsigned short int size, unsigned short int line_beg, unsigned short int col){
	for (unsigned short int i(0); i < size; ++i){
		board[line_beg+i][col]->live();
	}
}

void Game_Board::drawDiag(unsigned short int size, unsigned short int line_beg, unsigned short int col_beg){
	for (unsigned short int i(0); i < size; ++i){
		board[line_beg+i][col_beg+i]->live();
	}
}
