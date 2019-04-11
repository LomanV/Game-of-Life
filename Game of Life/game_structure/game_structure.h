#pragma once

#include "../vector2d/vector2d.h"
#include "../general/dessinable.h"
#include "../general/support_a_dessin.h"
#include "../constants/constants.h"

#include <vector>

enum State : bool {
	DEAD, 
	ALIVE
};
enum System_state : bool {
	CACHE,
	CURRENT
};

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
	
	void change_state(State my_state); 
	void die(void);
	void live(void);

	State getState(void) const {return state;}
	SupportADessin* getCanvas(void) const {return support;}
	Vector2D getPosition(void) const {return position;}

	virtual void dessine(void) override { support->dessine(*this); }
}; 

class Line : public Dessinable {
	private :
	std::vector<Unit*> line; 

	public :

	// constructor and initialisation
	Line(SupportADessin* canvas, unsigned short int y_pos) :
	Dessinable(canvas)
	{
		initialise(y_pos);
	}

	~Line() {
		for (auto cell : line) delete cell;
	}

	void initialise(unsigned short int y_pos); 
}; 

class Game_Board : public Dessinable {
	friend class VueOpenGL;
	friend class System;

	private :
	std::vector<std::vector<Unit*>> board; 
	System_state state;

	public :

	// constructor and initialisation
	Game_Board(SupportADessin* support, System_state my_state) :
	Dessinable(support),
	state(my_state)
	{
		initialise();
	}
	
	~Game_Board() {
		for (auto line : board){
			for (auto unit : line){
				delete unit;
			}
		}
	}

	Game_Board(Game_Board const& board) = delete; 
	Game_Board operator=(Game_Board const& board) = delete;

	void initialise(void);
	virtual void dessine(void) override { support->dessine(*this); }
	System_state getSystem_state(void) const { return state; }

	void drawLine(unsigned short int size, unsigned short int line, unsigned short int col_beg); 
	void drawCol(unsigned short int size, unsigned short int line_beg, unsigned short int col_beg);
	void drawDiag(unsigned short int size, unsigned short int line_beg, unsigned short int col_beg);

	void light_spaceship(unsigned short int line_beg, unsigned short int col_beg); 
	void mid_spaceship(unsigned short int line_beg, unsigned short int col_beg);
	void square(unsigned short int line_beg, unsigned short int col_beg); 
	void toad(unsigned short int line_beg, unsigned short int col_beg);
	void pulsar(unsigned short int line_beg, unsigned short int col_beg);
	void beacon(unsigned short int line_beg, unsigned short int col_beg);
	void glider(unsigned short int line_beg, unsigned short int col_beg);
	void larger_blinker(unsigned short int line_beg, unsigned short int col_beg);
	void acorn(unsigned short int line_beg, unsigned short int col_beg);
	void die_hard(unsigned short int line_beg, unsigned short int col_beg);
	void R_pentomino(unsigned short int line_beg, unsigned short int col_beg);
	void Pi_heptomino(unsigned short int line_beg, unsigned short int col_beg);
	void checker_board(void);
	void nice_board(void);
	void gosper_glider_gun(unsigned short int line_beg, unsigned short int col_beg);

	void swap_state(void);
	unsigned int count_live(Unit const& unit, unsigned short int line, unsigned short int col) const;
	State update(Unit const& unit, unsigned short int line, unsigned short int col) const;
}; 

class System : public Dessinable {
	friend class VueOpenGL;

	private :
	Game_Board instance1;
	Game_Board instance2;

	public :

	// constructor and initialisation
	System(SupportADessin* support) :
	Dessinable(support),
	instance1(support, CURRENT),
	instance2(support, CACHE) {}

	virtual void dessine(void) override { support->dessine(*this); }
	
	void drawLine(unsigned short int size, unsigned short int line, unsigned short int col_beg) {instance1.drawLine(size, line, col_beg); instance2.drawLine(size, line, col_beg);} 
	void drawCol(unsigned short int size, unsigned short int line_beg, unsigned short int col) {instance1.drawCol(size, line_beg, col); instance2.drawCol(size, line_beg, col);} 
	void drawDiag(unsigned short int size, unsigned short int line_beg, unsigned short int col_beg) {instance1.drawCol(size, line_beg, col_beg); instance2.drawCol(size, line_beg, col_beg);} 


	void light_spaceship(unsigned short int line_beg, unsigned short int col_beg) {instance1.light_spaceship(line_beg, col_beg); instance2.light_spaceship(line_beg, col_beg);} 
	void mid_spaceship(unsigned short int line_beg, unsigned short int col_beg)  {instance1.mid_spaceship(line_beg, col_beg); instance2.mid_spaceship(line_beg, col_beg);} 
	void square(unsigned short int line_beg, unsigned short int col_beg) {instance1.square(line_beg, col_beg); instance2.square(line_beg, col_beg);} 
	void toad(unsigned short int line_beg, unsigned short int col_beg) {instance1.toad(line_beg, col_beg); instance2.toad(line_beg, col_beg);} 
	void pulsar(unsigned short int line_beg, unsigned short int col_beg) {instance1.pulsar(line_beg, col_beg); instance2.pulsar(line_beg, col_beg);} 
	void beacon(unsigned short int line_beg, unsigned short int col_beg) {instance1.beacon(line_beg, col_beg); instance2.beacon(line_beg, col_beg);} 
	void glider(unsigned short int line_beg, unsigned short int col_beg) {instance1.glider(line_beg, col_beg); instance2.glider(line_beg, col_beg);} 
	void larger_blinker(unsigned short int line_beg, unsigned short int col_beg) {instance1.larger_blinker(line_beg, col_beg); instance2.larger_blinker(line_beg, col_beg);} 
	void acorn(unsigned short int line_beg, unsigned short int col_beg) {instance1.acorn(line_beg, col_beg); instance2.acorn(line_beg, col_beg);} 
	void die_hard(unsigned short int line_beg, unsigned short int col_beg) {instance1.die_hard(line_beg, col_beg); instance2.die_hard(line_beg, col_beg);} 
	void R_pentomino(unsigned short int line_beg, unsigned short int col_beg) {instance1.R_pentomino(line_beg, col_beg); instance2.R_pentomino(line_beg, col_beg);} 
	void checker_board(void) {instance1.checker_board(); instance2.checker_board(); }
	void nice_board(void) {instance1.nice_board(); instance2.nice_board(); }
	void gosper_glider_gun(unsigned short int line_beg, unsigned short int col_beg) {instance1.gosper_glider_gun(line_beg, col_beg); instance2.gosper_glider_gun(line_beg, col_beg);}

	System(System const& s) = delete;
	System operator=(System const& s) = delete;

	void swap_state(void);
	void update_cache(void);
}; 
