==================
Basic-Notepad
==================

This is a simple notepad written in C++ using Qt. 
This application can open, close and save files. 
There is one class used in this application. It is called notepad. 

The notepad class has the following private members. 
      QTextEdit *tEditor;
      QPushButton *quitButton;

      QAction *openAction;
      QAction *saveAction;
      QAction *quitAction;
      
The notepad class has the following slots. 
      void open();
      void save();
      void Quit();
      
M.S.Adityan
www.msadityan.com

