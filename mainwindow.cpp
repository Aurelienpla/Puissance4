#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grillejeux.h"
#include <QList>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   QList<QPushButton*> mListPb;
   QSignalMapper * signalMapper = new QSignalMapper();
   mListPb<<ui->mPbCol0<<ui->mPbCol1<<ui->mPbCol2<<ui->mPbCol3<<ui->mPbCol4<<ui->mPbCol5<<ui->mPbCol6<<ui->mPbCol7;
   for (int i = 0; i < mListPb.count(); i++) {
      connect(mListPb[i],SIGNAL(clicked(bool)),signalMapper,SLOT(map()));
      signalMapper->setMapping(mListPb[i],i);
   }

   connect(ui->mMenuReset,SIGNAL(triggered(bool)),ui->mGrilleJeux,SLOT(reset()));

   connect(signalMapper,SIGNAL(mapped(int)),this,SLOT(onPbClicked(int)));

   //intialisation de la grille avec le meme nombre de colonne que de boutons
   ui->mGrilleJeux->setDimension(mListPb.count(),NBLIGNE);

   mPlayer = PLAYERRED;
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::onPbClicked(int idPb)
{
   if(mPlayer == PLAYERRED){
      ui->mGrilleJeux->addPiece(idPb,GrilleJeux::RED);
      mPlayer = PLAYERYELLOW;
   } else {
      ui->mGrilleJeux->addPiece(idPb,GrilleJeux::YELLOW);
      mPlayer = PLAYERRED;
   }
}
