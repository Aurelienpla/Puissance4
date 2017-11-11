#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   enum Player{PLAYERRED,PLAYERYELLOW};

   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

private:
   Ui::MainWindow *ui;
   Player mPlayer;

private slots:
   void onPbClicked(int idPb);
};

#endif // MAINWINDOW_H
