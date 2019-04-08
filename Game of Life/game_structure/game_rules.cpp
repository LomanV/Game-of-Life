#include "game_structure.h"

unsigned int Game_Board::count_live(Unit const& unit, size_t line, size_t col) const{
	unsigned int res(0);
	for (size_t i(line-1); i <= line+1; ++i){
		for (size_t j(col-1); j <= col+1; ++j){
			if (board[i][j]->getState() == ALIVE and (i!= line or j != col)) ++res;
		}
	}
	return res;
}

State Game_Board::update(Unit const& unit, size_t line, size_t col) const{
	unsigned int count_live = this->count_live(unit, line, col);
	if (unit.getState() == ALIVE){
		if (count_live < 2) return DEAD;
		if (count_live == 3 or count_live == 2) return ALIVE;
		if (count_live > 3) return DEAD;
	}
	else if (unit.getState() == DEAD and count_live == 3) return ALIVE;
	return unit.getState();
}

void Game_Board::swap_state(void){
	if (state == CACHE) state = CURRENT;
	else if (state == CURRENT) state = CACHE;
}
void System::swap_state(void){
	instance1.swap_state();
	instance2.swap_state();
}

void System::update_cache(void){
	if (instance1.state == CACHE) {
		for (size_t i(1); i < game::BOARD_SIZE-1; ++i){
			for (size_t j(1); j < game::BOARD_SIZE-1; ++j){
				instance2.board[i][j]->change_state(instance1.update(*instance1.board[i][j], i, j));
			}
		}
	}
	else if (instance2.state == CACHE){
		for (size_t i(2); i < game::BOARD_SIZE-1; ++i){
			for (size_t j(1); j < game::BOARD_SIZE-1; ++j){
				instance1.board[i][j]->change_state(instance2.update(*instance2.board[i][j], i, j));
			}
		}
	}
	swap_state();
}
