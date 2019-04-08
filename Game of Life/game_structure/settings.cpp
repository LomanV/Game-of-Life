#include "game_structure.h"

void Game_Board::light_spaceship(size_t line_beg, size_t col_beg){
	if (line_beg >= game::BOARD_SIZE - 2 or col_beg >= game::BOARD_SIZE - 4){
	   int erreur(0);
	   throw erreur;
	}
	board[line_beg - 1][col_beg + 1]->live(); board[line_beg - 1][col_beg + 2]->live(); board[line_beg - 1][col_beg + 3]->live(); board[line_beg - 1][col_beg + 4]->live();
	 board[line_beg][col_beg + 4]->live(); board[line_beg + 1][col_beg + 4]->live(); board[line_beg + 2][col_beg + 3]->live(); board[line_beg + 2][col_beg]->live(); board[line_beg][col_beg]->live();
}

void Game_Board::square(size_t line_beg, size_t col_beg){
	if (line_beg >= game::BOARD_SIZE - 1 or line_beg < 0 or col_beg >= game::BOARD_SIZE - 1 or col_beg < 0){
		int erreur(0);
		throw erreur;
	}
	board[line_beg][col_beg]->live(); board[line_beg + 1][col_beg]->live(); board[line_beg][col_beg + 1]->live(); board[line_beg + 1][col_beg + 1]->live();
}

void Game_Board::toad(size_t line_beg, size_t col_beg){
	if (line_beg < 1 or line_beg >= game::BOARD_SIZE + 2 or col_beg < 1 or col_beg >= game::BOARD_SIZE - 2) {
		int erreur(0);
		throw erreur;
	}
	board[line_beg - 1][col_beg + 1]->live(); board[line_beg][col_beg  -1]->live(); board[line_beg + 1][col_beg - 1]->live(); board[line_beg + 2][col_beg]->live();
	board[line_beg][col_beg + 2]->live(); board[line_beg + 1][col_beg + 2]->live();
}

void Game_Board::pulsar(size_t line_beg, size_t col_beg){
	try {
		for (int i(0); i <= 12; ++i){
			if (i == 0 or i == 5 or i == 7 or i == 12){
				drawLine(3, line_beg + i, col_beg + 2);
				drawLine(3, line_beg + i, col_beg + 8);
				drawCol(3, line_beg + 2, col_beg + i);
				drawCol(3, line_beg + 8, col_beg + i);
			}
		}
	} catch (int erreur){
		int err(0);
		throw err;
	}
}

void Game_Board::beacon(size_t line_beg, size_t col_beg){
	if (line_beg < 0 or line_beg >= game::BOARD_SIZE - 2 or col_beg < 0 or col_beg >= game::BOARD_SIZE - 2){
		int erreur(0);
		throw erreur;
	}
	board[line_beg - 1][col_beg - 1]->live(); board[line_beg - 1][col_beg]->live(); board[line_beg][col_beg - 1]->live();
	board[line_beg + 1][col_beg + 2]->live(); board[line_beg + 2][col_beg + 1]->live(); board[line_beg + 2][col_beg + 2]->live();
}

void Game_Board::glider(size_t line_beg, size_t col_beg){
	if (line_beg < 0 or line_beg >= game::BOARD_SIZE - 2 or col_beg < 0 or col_beg >= game::BOARD_SIZE - 2){
		int erreur(0);
		throw erreur;
	}
	board[line_beg][col_beg]->live(); board[line_beg][col_beg + 2]->live(); board[line_beg + 1][col_beg + 1]->live(); board[line_beg + 1][col_beg + 2]->live(); board[line_beg + 2][col_beg + 1]->live();
}

void Game_Board::mid_spaceship(size_t line_beg, size_t col_beg){
	if (line_beg < 0 or line_beg >= game::BOARD_SIZE - 4 or col_beg < 0 or col_beg >= game::BOARD_SIZE - 5){
		int erreur(0);
		throw erreur;
	}
	board[line_beg][col_beg]->live(); board[line_beg][col_beg + 1]->live(); board[line_beg][col_beg + 2]->live(); board[line_beg][col_beg + 3]->live(); board[line_beg][col_beg + 4]->live(); 
	board[line_beg + 1][col_beg]->live(); board[line_beg + 1][col_beg + 5]->live(); board[line_beg + 2][col_beg]->live(); board[line_beg + 3][col_beg + 1]->live();
	board[line_beg + 3][col_beg + 5]->live(); board[line_beg + 4][col_beg + 3]->live(); 
}

void Game_Board::larger_blinker(size_t line_beg, size_t col_beg){
	try {
		drawLine(3, line_beg, col_beg);
		drawCol(3, line_beg -1, col_beg + 1);
	} catch (int erreur){
		int err(0); 
		throw err;
	}
}

void Game_Board::acorn(size_t line_beg, size_t col_beg){
	if (line_beg < 0 or line_beg >= game::BOARD_SIZE - 1 or col_beg < 0 or col_beg >= game::BOARD_SIZE - 3){
		int err(0);
		throw err;
	}
	try {
		drawLine(2, line_beg + 2, col_beg);
		drawLine(3, line_beg + 2, col_beg + 4);
	} catch (int erreur){
		int err(0);
		throw err;
	}
	board[line_beg][col_beg + 1]->live(); board[line_beg + 1][col_beg + 3]->live();
}

void Game_Board::die_hard(size_t line_beg, size_t col_beg){
	if (line_beg < 0 or line_beg >= game::BOARD_SIZE - 2 or col_beg < 0 or col_beg >= game::BOARD_SIZE - 6){
		int err(0);
		throw err;
	}
	try {
		drawLine(3, line_beg + 2, col_beg + 5);
		drawLine(2, line_beg + 1, col_beg);
	} catch (int erreur){
		int err(0);
		throw err;
	}
	board[line_beg + 2][col_beg + 1]->live(); board[line_beg][col_beg + 6]->live();
}

void Game_Board::R_pentomino(size_t line_beg, size_t col_beg){
	if (line_beg < 0 or line_beg >= game::BOARD_SIZE - 1 or col_beg < 0 or col_beg >= game::BOARD_SIZE - 2){
		int err(0);
		throw err;
	}
	try {
		drawCol(3, line_beg, col_beg + 1);
	} catch (int erreur){
		int err(0);
		throw err;
	}
	board[line_beg + 1][col_beg]->live(); board[line_beg][col_beg + 2]->live();
}

void Game_Board::Pi_heptomino(size_t line_beg, size_t col_beg){
	try {
		drawCol(3, line_beg, col_beg);
		drawCol(3, line_beg, col_beg + 2);
	} catch (int erreur){
		int err(0);
		throw err;
	}
	board[line_beg][col_beg + 1]->live();
}

void Game_Board::nice_board(void){
	for (size_t i(2); i < game::BOARD_SIZE - 2; ++i){
		for (size_t j(2); j < game::BOARD_SIZE - 2; ++j){
			if (i%2 == 0 and j%2 == 0){
				board[i][j]->live();
			}
		}
	}
}

void Game_Board::checker_board(void){
	for (size_t i(2); i < game::BOARD_SIZE - 1; ++i){
		for (size_t j(2); j < game::BOARD_SIZE - 1; ++j){
			if (i%2 != j%2){
				board[i][j]->live();
			}
		}
	}
}

void Game_Board::gosper_glider_gun(size_t line_beg, size_t col_beg){
	square(line_beg, col_beg);
	drawCol(3,line_beg, col_beg+10);
	board[line_beg -1][col_beg+11]->live();
	board[line_beg +3][col_beg+11]->live();
	drawLine(2, line_beg-2, col_beg+12);
	drawLine(2,line_beg+4, col_beg+12);
	board[line_beg+1][col_beg+14]->live();
	board[line_beg -1][col_beg+15]->live();
	board[line_beg +3][col_beg+15]->live();
	drawCol(3,line_beg, col_beg+16);
	board[line_beg+1][col_beg+17]->live();
	drawCol(3,line_beg-2, col_beg+20);
	drawCol(3,line_beg-2, col_beg+21);
	board[line_beg+1][col_beg+22]->live();
	board[line_beg-3][col_beg+22]->live();
	drawCol(2, line_beg+1,col_beg+24);
	drawCol(2, line_beg-4,col_beg+24);
	square(line_beg-2, col_beg+34);
}
