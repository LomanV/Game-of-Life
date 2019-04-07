#include "vue_opengl.h"
#include "vertex_shader.h"
#include "../vector2d/vector2d.h"
#include "../constants/constants.h"

#include <cmath>

// ======================================================================
void VueOpenGL::init()
{

  prog.addShaderFromSourceFile(QOpenGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fragment_shader.glsl");

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);

  prog.link();

  prog.bind();

  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_CULL_FACE);

  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, (-0.08)*game::BOARD_SIZE);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================

 void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);

  glEnd();
}

// ======================================================================

void VueOpenGL::dessineCarre (QMatrix4x4 const& pov, Vector2D const& bottom_right_corner, double side, bool color){

    prog.setUniformValue("vue_modele", matrice_vue * pov);
    if (color){
	    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0);
    } else {prog.setAttributeValue(CouleurId, 1.0,0.0,0.0);}

    glBegin((GL_QUADS));
    glVertex2d(bottom_right_corner[0], bottom_right_corner[1]);
    glVertex2d(bottom_right_corner[0], bottom_right_corner[1]+side);
    glVertex2d(bottom_right_corner[0]+side, bottom_right_corner[1]+side);
    glVertex2d(bottom_right_corner[0]+side, bottom_right_corner[1]);
    glEnd();
}

// ======================================================================

void VueOpenGL::dessine(Unit const& unit){
    QMatrix4x4 matrix;
    State state = unit.getState();
    if (state == ALIVE) {
	    dessineCarre(matrix, unit.getPosition(), game::UNIT_SIZE, true);
    } 
}

// ======================================================================

void VueOpenGL::dessine(Game_Board const& board){
    for (auto units : board.board){
		for (auto unit : units){
		        dessine(*unit);
		}
	}
}

// =====================================================================

void VueOpenGL::dessine(System const& system){
	if (system.instance1.getSystem_state() == CURRENT){
		dessine(system.instance1);
	}
	else if (system.instance2.getSystem_state() == CURRENT){
		dessine(system.instance2);
	}
}
