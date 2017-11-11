#include "grillejeux.h"
#include <QPainter>


GrilleJeux::GrilleJeux(QWidget *parent) : QWidget(parent)
{
//   for (int i = 0 ; i < NBCOLONNE ; i++){
//      QList<Piece> * col = new QList<Piece>();
//      for(int j = 0 ; j < NBLINE; j++){
//         col->append(NONE);
//      }
//      mListPiece.append(*col);
//   }
}

GrilleJeux::~GrilleJeux()
{

}

bool GrilleJeux::addPiece(int col, GrilleJeux::Piece p)
{
   if (mListPiece[col][0] == NONE){
      int iLine = NBLIGNE - 1;
      while (iLine > 0 && mListPiece[col][iLine] != NONE){
         iLine--;
      }
      mListPiece[col][iLine] = p;
      update();
      return true;
   }
   return false;
}

void GrilleJeux::setDimension(int nbCol, int nbLigne)
{
   for (int i = 0 ; i < nbCol ; i++){
      QList<Piece> * col = new QList<Piece>();
      for(int j = 0 ; j < nbLigne; j++){
         col->append(NONE);
      }
      mListPiece.append(*col);
   }
}

void GrilleJeux::reset()
{
   for (int iCol = 0; iCol < mListPiece.count(); iCol++) {
      for (int iLine = 0; iLine < mListPiece[iCol].count(); iLine++) {
         mListPiece[iCol][iLine] = NONE;
      }
   }
   update();
}

void GrilleJeux::paintEvent(QPaintEvent * paintEvent)
{
   QPainter painter(this);
   painter.setBrush(Qt::blue);
   painter.drawRect(0,0,width(),height());

   int largeurPiece = width() / mListPiece.count();
   int hauteurPiece = height() / mListPiece[0].count();

   for (int iCol = 0 ; iCol < mListPiece.count() ; iCol++){
      for (int iLine = 0; iLine < mListPiece[iCol].count() ; iLine++){
         painter.setBrush((Qt::GlobalColor) mListPiece[iCol].at(iLine));
         painter.drawEllipse(largeurPiece * iCol, hauteurPiece * iLine, largeurPiece, hauteurPiece);
      }
   }
}
