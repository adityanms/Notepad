#include<QtGui>

class notepad : public QMainWindow
{
  Q_OBJECT;
public:
  notepad();
  private:
      QTextEdit *tEditor;
      QPushButton *quitButton;

      QAction *openAction;
      QAction *saveAction;
      QAction *quitAction;

      QMenu *fileMenu;
  private slots:
      void open();
      void save();
      void Quit();

};
