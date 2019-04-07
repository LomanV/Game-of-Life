#pragma once

#include "../vector2d/vector2d.h"
#include "../general/dessinable.h"
#include "../general/support_a_dessin.h"
#include "../constants/constants.h"

#include <array>

enum State {DEAD, ALIVE};
enum System_state {CACHE, CURRENT};

class Unit : public Dessinable {
	private :
	Vector2D position;
	State state;

	public :
	Unit(SupportADessin* canvas, Vector2D my_position = vctr::ZERO_VECTOR, State my_state = DEAD) : 
	Dessinable(canvas),
	position(my_position),
	state(my_state)
	{}
	
	void change_state(void); 
	void die(void);
	void live(void);

	State getState(void) const {return state;}
	SupportADessin* getCanvas(void) const {return support;}
	Vector2D getPosition(void) const {return position;}

	virtual void dessine(void) override { support->dessine(*this); }
}; 

class Game_Board : public Dessinable {
	friend class VueOpenGL;
	friend class System;

	private :
	std::array<std::array<Unit*, game::BOARD_SIZE>, game::BOARD_SIZE> board; 
	System_state state;

	public :
	Game_Board(SupportADessin* support, System_state my_state) :
	Dessinable(support),
	state(my_state)
	{
		initialise();
	}
	
	~Game_Board() {
		for (auto units : board){
			for (auto unit : units){
				delete unit;
			}
		}
	}

	Game_Board(Game_Board const& board) = delete; 
	Game_Board operator=(Game_Board const& board) = delete;

	void initialise(void);
	virtual void dessine(void) override { support->dessine(*this); }
	System_state getSystem_state(void) const { return state; }

	void drawLine(size_t size, size_t line, size_t col_beg); 
	void drawCol(size_t size, size_t line_beg, size_t col_beg);
	void drawDiag(size_t size, size_t line_beg, size_t col_beg);

	void light_spaceship(size_t line_beg, size_t col_beg); 
	void mid_spaceship(size_t line_beg, size_t col_beg);
	void square(size_t line_beg, size_t col_beg); 
	void toad(size_t line_beg, size_t col_beg);
	void pulsar(size_t line_beg, size_t col_beg);
	void beacon(size_t line_beg, size_t col_beg);
	void glider(size_t line_beg, size_t col_beg);
	void larger_blinker(size_t line_beg, size_t col_beg);
	void acorn(size_t line_beg, size_t col_beg);
	void die_hard(size_t line_beg, size_t col_beg);
	void R_pentomino(size_t line_beg, size_t col_beg);
	void Pi_heptomino(size_t line_beg, size_t col_beg);
	void checker_board(void);
	void nice_board(void);
	// void gosper_glider_gun(size_t line_beg, size_t col_beg);

	void swap_state(void);
	unsigned int count_live(Unit const& unit, size_t line, size_t col) const;
	State update(Unit const& unit, size_t line, size_t col) const;
}; 

class System : public Dessinable {
	friend class VueOpenGL;

	Game_Board instance1;
	Game_Board instance2;
	public :
	System(SupportADessin* support) :
	Dessinable(support),
	instance1(support, CURRENT),
	instance2(support, CACHE) {}

	virtual void dessine(void) override { support->dessine(*this); }
	
	void drawLine(size_t size, size_t line, size_t col_beg) {instance1.drawLine(size, line, col_beg); instance2.drawLine(size, line, col_beg);} 
	void drawCol(size_t size, size_t line_beg, size_t col) {instance1.drawCol(size, line_beg, col); instance2.drawCol(size, line_beg, col);} 
	void drawDiag(size_t size, size_t line_beg, size_t col_beg) {instance1.drawCol(size, line_beg, col_beg); instance2.drawCol(size, line_beg, col_beg);} 


	void light_spaceship(size_t line_beg, size_t col_beg) {instance1.light_spaceship(line_beg, col_beg); instance2.light_spaceship(line_beg, col_beg);} 
	void mid_spaceship(size_t line_beg, size_t col_beg)  {instance1.mid_spaceship(line_beg, col_beg); instance2.mid_spaceship(line_beg, col_beg);} 
	void square(size_t line_beg, size_t col_beg) {instance1.square(line_beg, col_beg); instance2.square(line_beg, col_beg);} 
	void toad(size_t line_beg, size_t col_beg) {instance1.toad(line_beg, col_beg); instance2.toad(line_beg, col_beg);} 
	void pulsar(size_t line_beg, size_t col_beg) {instance1.pulsar(line_beg, col_beg); instance2.pulsar(line_beg, col_beg);} 
	void beacon(size_t line_beg, size_t col_beg) {instance1.beacon(line_beg, col_beg); instance2.beacon(line_beg, col_beg);} 
	void glider(size_t line_beg, size_t col_beg) {instance1.glider(line_beg, col_beg); instance2.glider(line_beg, col_beg);} 
	void larger_blinker(size_t line_beg, size_t col_beg) {instance1.larger_blinker(line_beg, col_beg); instance2.larger_blinker(line_beg, col_beg);} 
	void acorn(size_t line_beg, size_t col_beg) {instance1.acorn(line_beg, col_beg); instance2.acorn(line_beg, col_beg);} 
	void die_hard(size_t line_beg, size_t col_beg) {instance1.die_hard(line_beg, col_beg); instance2.die_hard(line_beg, col_beg);} 
	void R_pentomino(size_t line_beg, size_t col_beg) {instance1.R_pentomino(line_beg, col_beg); instance2.R_pentomino(line_beg, col_beg);} 
	void checker_board(void) {instance1.checker_board(); instance2.checker_board(); }
	void nice_board(void) {instance1.nice_board(); instance2.nice_board(); }
	// void gosper_glider_gun(size_t line_beg, size_t col_beg);

	System(System const& s) = delete;
	System operator=(System const& s) = delete;

	void swap_state(void);
	void update_cache(void);
}; 
