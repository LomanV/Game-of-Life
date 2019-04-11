#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include "../general/support_a_dessin.h"
#include "../vector2d/vector2d.h"
#include "../game_structure/game_structure.h"

class VueOpenGL : public SupportADessin {
 public:
  void init();
  void initializePosition();

  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  void translate(double x, double y, double z);
  
  void dessineAxes (QMatrix4x4 const& pov, bool en_couleur);
  void dessineCarre(QMatrix4x4 const& pov, Vector2D const& bottom_right_corner, double side, bool color);

  void dessine(Unit const& unit) override;
  void dessine(Line const& line) override;
  void dessine(Game_Board const& board) override;
  void dessine(System const& system) override;

 private:
  QOpenGLShaderProgram prog;
  QMatrix4x4 matrice_vue;

};

#endif
