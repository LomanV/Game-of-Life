#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>        
#include <QTime>            

#include "vue_opengl.h"
#include "../game_structure/game_structure.h"

class GLWidget : public QOpenGLWidget, public System 
{
public:
  GLWidget(QWidget* parent = nullptr)
    : QOpenGLWidget(parent),
      System(&vue)

  {}
  virtual ~GLWidget() {}

private:
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  virtual void keyPressEvent(QKeyEvent* event) override;

  void pause();

  VueOpenGL vue;

  int timerId;
  QTime chronometre;
};

#endif // GLWIDGET_H
