#include <QApplication>
#include "glwidget.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  w.drawCol(990, 5, 500);
  w.show();

  return a.exec();
}
