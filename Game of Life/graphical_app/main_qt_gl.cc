#include <QApplication>
#include "glwidget.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  w.R_pentomino(100, 100);
  w.show();

  return a.exec();
}
