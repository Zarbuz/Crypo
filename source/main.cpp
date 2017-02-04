#include <QApplication>
#include <QtGui>
#include <QObject>
#include "FenPrincipale.h"

//Début du programme ici !
//Le main est très petit. Tout est réaliser grâce à la POO

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale fenetre; //On déclare une nouvelle fenetre de la classe "FenPrincipale" qu'on a déclarer
    fenetre.setFixedSize(703,579); //On met une taille FIXE
    fenetre.setWindowIcon(QIcon("img/icone.png")); //Une icone
    fenetre.show(); //On affiche la fenêtre

    return app.exec(); //On execute l'app. Notion à détaillé particulière à Qt
    //Suite vers FenPrincipale.h
}
