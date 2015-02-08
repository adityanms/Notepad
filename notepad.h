#include<QtGui>

class notepad : public QMainWindow
{
  Q_OBJECT;
public:
  notepad();
  private slots:
      void open();
      void save();
      void Quit();
private:
      QTextEdit *tEditor;
      QPushButton *quitButton;

      QAction *openAction;
      QAction *saveAction;
      QAction *quitAction;

      QMenu *fileMenu;
};
