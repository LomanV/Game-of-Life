#include <QApplication>
#include "glwidget.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);
  GLWidget w;
  w.checker_board();
  w.show();

  return a.exec();
}
