// A simple notepad written in C++ by M.S.Adityan

#include "notepad.h"

int main(int argc, char **argv)
{
  QApplication nPad(argc, argv);
  notepad *window = new notepad();
  window->show();
  return nPad.exec();
}
