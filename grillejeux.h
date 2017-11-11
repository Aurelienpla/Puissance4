#ifndef GRILLEJEUX_H
#define GRILLEJEUX_H

#include <QWidget>
#include <QList>
#include <QPaintEvent>

#define NBLIGNE 6
#define NBCOLONNE 7

class GrilleJeux : public QWidget
{
   Q_OBJECT


public:
   GrilleJeux(QWidget *parent = nullptr);
   virtual ~GrilleJeux();

   enum Piece{NONE=Qt::black,YELLOW=Qt::yellow,RED=Qt::red};

   bool addPiece(int col, Piece p);
   void setDimension(int nbCol = NBCOLONNE, int nbLigne = NBLIGNE);

signals:

public slots:
   void reset();

protected:
   void paintEvent(QPaintEvent * paintEvent);

private:
   QList<QList<Piece>> mListPiece;
};

#endif // GRILLEJEUX_H
