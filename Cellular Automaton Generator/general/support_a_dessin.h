#ifndef SUPPORT_A_DESSIN_H
#define SUPPORT_A_DESSIN_H

class Unit;
class Game_Board;
class System;

class SupportADessin
{
 public:
  virtual ~SupportADessin() {}

  virtual void dessine(Unit const& unit) = 0;
  virtual void dessine(Game_Board const& board) = 0;
  virtual void dessine(System const& system) = 0;

  private:
    SupportADessin& operator=(SupportADessin const&) = delete;
};

#endif
