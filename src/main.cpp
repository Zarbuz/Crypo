#include <QApplication>
#include <QtGui>
#include <QObject>
#include "FenPrincipale.h"

//D�but du programme ici !
//Le main est tr�s petit. Tout est r�aliser gr�ce � la POO

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetre; //On d�clare une nouvelle fenetre de la classe "FenPrincipale" qu'on a d�clarer
    fenetre.setFixedSize(703,579); //On met une taille FIXE
    fenetre.setWindowIcon(QIcon("img/icone.png")); //Une icone
    fenetre.show(); //On affiche la fen�tre

    return app.exec(); //On execute l'app. Notion � d�taill� particuli�re � Qt
    //Suite vers FenPrincipale.h
}
