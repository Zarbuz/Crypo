#ifndef FENHISTORIQUE_H
#define FENHISTORIQUE_H

#include <QtGui>
#include "Conversions.h"

class FenHistorique : public QDialog //C'est une simple fenêtre temporaire, un QDialog suffis amplement
 {
    Q_OBJECT

public slots:
    void attrapeSortie();
    void attrapeEntree();
    void attrapeTous();
    void viderSlot();

signals:
    void attrapeSignal(QString);

protected:
    void fermerEvent(QCloseEvent *event);

public:
    FenHistorique(QWidget *parent = 0);
    QTextEdit *textEdit;
    QPushButton *boutonVider;

private:

    Conversion *conv;

    QPushButton *boutonAttraperEntrer;
    QPushButton *boutonAttraperSortie;
    QPushButton *boutonAttraperTous;



};

#endif // FENHISTORIQUE_H
