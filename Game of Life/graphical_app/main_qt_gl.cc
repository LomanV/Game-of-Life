#include <QApplication>
#include "glwidget.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  w.gosper_glider_gun(100, 100);
  w.show();

  return a.exec();
}
