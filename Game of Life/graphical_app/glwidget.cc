#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidget.h"

// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
  timerId = startTimer(20);
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  glViewport(0, 0, width, height);

  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  dessine();
}


// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_pas(1.0);

  switch (event->key()) {

  case Qt::Key_PageUp:
  case Qt::Key_Up:
    vue.translate(0.0, 0.0,  petit_pas);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_Down:
    vue.translate(0.0, 0.0, -petit_pas);
    break;

  case Qt::Key_Q:
    vue.translate( petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_D:
    vue.translate(-petit_pas, 0.0, 0.0);
    break;

  case Qt::Key_Z:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_S:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;

  case Qt::Key_Space:
	pause();
	break;
  };

  update(); // redessine
}

// ======================================================================

void GLWidget::pause()
{
  if (timerId == 0) {
	// dans ce cas le timer ne tourne pas alors on le lance
	timerId = startTimer(20);
	chronometre.restart();
  } else {
	// le timer tourne alors on l'arrête
	killTimer(timerId);
	timerId = 0;
  }
}
