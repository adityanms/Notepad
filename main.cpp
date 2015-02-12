// A simple notepad written in C++ by M.S.Adityan
// This application is capable of opening, closing and saving files. 
// www.msadityan.com

#include "notepad.h"
#include<QApplication>

int main(int argc, char *argv)
{
  QApplication nPad(argc, argv);
  notepad *window = new notepad();
  window->show();
  return nPad.exec();
}
