#include "notepad.h"

notepad::notepad()
{
  tEditor = new QTextEdit;
  quitButton = new QPushButton;

  openAction = new QAction(tr("Open"), this);
  saveAction = new QAction(tr("Save"), this);
  quitAction = new QAction(tr("Quit"), this);

  QObject::connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
  QObject::connect(saveAction, SIGNAL(triggered()), this, SLOT(save()));
  QObject::connect(quitAction, SIGNAL(triggered()), this, SLOT(Quit()));

  fileMenu = menuBar()->addMenu(tr("File"));
  fileMenu->addAction(openAction);
  fileMenu->addAction(saveAction);
  fileMenu->addAction(quitAction);

  setWindowTitle(tr("Notepad"));
  setCentralWidget(tEditor);
}

void notepad::open()
{
  QString fileName = QFileDialog::getOpenFileName(this, tr("Select a file... "), "", tr("Text Files (*.txt);;c++ source files (*.cpp);;All Files (*.*)"));
  if(fileName!="")
    {
      QFile fIn(fileName);
      if(!fIn.open(QIODevice::ReadOnly))
        {
          QMessageBox::critical(this, tr("Error"), tr("File could not opened"));
          return;
        }
        QTextStream in(&fIn);
        tEditor->setText(in.readAll());
        fIn.close();
    }
  else
  {
    QMessageBox confirm;
    confirm.setText(tr("No file has bee selected"));
    confirm.setStandardButtons(QMessageBox::Retry | QMessageBox::Ok);
    confirm.setDefaultButton(QMessageBox::Ok);

    if(confirm.exec()==QMessageBox::Retry)
    {
      open();
    }
  }
}

void notepad::save()
{
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;C++ Source Files (*.cpp);;All files(*.*)"));
  QFile fOut(fileName);
  if(fileName!="")
  {
    if(fOut.open(QIODevice::WriteOnly))
    {
      QTextStream out(&fOut);
      out<<tEditor->toPlainText();
      out.flush();
      fOut.close();
    }
    else
    {
      QMessageBox::critical(this, tr("Error !!!"), tr("File could not be saved"));
      return;
    }
  }
}

void notepad::Quit()
{
  QMessageBox confirmQuit;
  confirmQuit.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
  confirmQuit.setDefaultButton(QMessageBox::No);
  confirmQuit.setText(tr("Do you really want to quit ?"));
  confirmQuit.setWindowTitle(tr("Close the Notepad"));
  if(confirmQuit.exec() == QMessageBox::Yes)
  {
    qApp->quit();
  }
}
