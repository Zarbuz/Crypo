#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QtGui>
/* A la Roy va faloir que tu modifie quelque truc : les headers que je t'ai envoyer il y a pas longtemps : il faut que tu indique leur répertoire*/
#include "C:\Qt\2009.02\qt\include\cryptopp/aes.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/blowfish.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/camellia.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/cast.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/des.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/gost.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/idea.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/mars.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rc2.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rc5.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rc6.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/rijndael.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/safer.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/seed.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/serpent.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/shacal2.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/shark.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/skipjack.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/square.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/3way.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/twofish.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/tea.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/salsa.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/panama.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/seal.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/sosemanuk.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/modes.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/filters.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/hex.h"
#include "C:\Qt\2009.02\qt\include\cryptopp/sha.h"


#include "FenCrypter.h"
#include "Hashes.h"
#include "Encryptions.h"
#include "Conversions.h"
#include "FenHistorique.h"

class GenererCle : public QDialog //C'est la classe de la fenetre de la génération de la clé. Elle hérite d'une QDialog. C'est fonctionnalités sont donc limités.
{
    Q_OBJECT

    public :
    GenererCle(QWidget *parent=0); //Le constructeur
    QCheckBox *verifMajuscule; //Les différentes checkbox
    QCheckBox *verifMinuscule;
    QCheckBox *verifNombre;
    QCheckBox *verifSpecialCarac;
    QSpinBox  *longueur;

    private :
    QPushButton *boutonOk;
    QPushButton *boutonAnnuler;
    QLabel *labelLongueur;

};

class FenPrincipale : public QMainWindow //Le gros bouzin : la fenêtre principale elle hérite d'une classe qui possède presque tout.
{
    Q_OBJECT
public :
    FenPrincipale(); //Le constructeur

    enum functions {separateur, Adler32=1, CRC32, MD2, MD4, MD5, RIPEMD128, RIPEMD160, RIPEMD320, SHA1, SHA224, SHA256, SHA384, SHA512, Tiger, Whirlpool, //On fais une énumération de nos types de crypt/encod/hash qui va nous permettre d'associer la QComboBox à nos fonctions
                    separateur1, AES, AES_D, Blowfish, Blowfish_D, Camellia, Camellia_D, CAST128, CAST128_D, CAST256, CAST256_D,
                    DES, DES_D, DES_EDE2, DES_EDE2_D, DES_EDE3, DES_EDE3_D, DES_XEX3, DES_XEX3_D, GOST, GOST_D, IDEA, IDEA_D, MARS,
                    MARS_D, Panama, Panama_D, RC2, RC2_D, RC5, RC5_D, RC6, RC6_D, SAFER_K, SAFER_K_D, SAFER_SK, SAFER_SK_D, Salsa20, Salsa20_D, SEED, SEED_D, SEAL, SEAL_D, Serpent, Serpent_D,
                    SHACAL2, SHACAL2_D, SHARK, SHARK_D, SKIPJACK, SKIPJACK_D, Sosemanuk, Sosemanuk_D, Square, Square_D, TEA, TEA_D, ThreeWay, ThreeWay_D,
                    Twofish, Twofish_D, XSalsa20, XSalsa20_D, XTEA, XTEA_D,
                    separateur2, Base32Encode, Base32Decode, Base64Encode, Base64Decode, HexEncode, HexDecode, Reverse, Rot13Encode,
                    URLEncode, URLDecode, UUEncode, UUDecode
                   }; //les separateur sont les "mini-menus" tel que "######hashing####" et donc sépare les différents types d'algorithmes

public slots : //Les différents SLOTS qui sont appelés lors d'une exécution d'un bouton..... (TYPE : PUBLIC)
    void selectionCrypt();
    void vider();
    void echanger();
    void copier();
    void historiqueSlot();
    void genererCleSlot();
    void genererCleOptSlot();
    void lireReglages();
    void ecrireReglages();
    void attraperSignal(QString);


protected:
    void fermerEvent(QCloseEvent *event);

private :

    void champNonCrypterActiver(bool statut);
    QTabWidget *onglets;

    QWidget *pageCrypter;
    QWidget *pageDecrypter;
    QWidget *pageHash;

    QHBoxLayout *layout; //Je sais : il faut toujours donner un nom explicite à ses variables
    QHBoxLayout *layout2;
    QHBoxLayout *layout3;

    QVBoxLayout *layoutPrincipale;
    QVBoxLayout *layoutPrincipale2;

    QLabel *labelCryptage;
    QLabel *labelCle;
    QLabel *labelHash;


    QComboBox *listeCryptage1;
    QComboBox *listeCryptage2;
    QComboBox *listeHash;

    QPushButton *boutonQuitter;
    QPushButton *boutonVider;
    QPushButton *boutonEchanger;
    QPushButton *boutonCopier;
    QPushButton *boutonGenererCle;
    QPushButton *boutonOutils;

    QTextEdit *champNonCrypter;
    QTextEdit *champCrypter;

    QTextEdit *champHashNonCrypter;
    QTextEdit *champHashCrypter;

    QLineEdit *ligneCle;

    QAction *minuscule;
    QAction *majuscule;
    QAction *historique;
    QAction *genererCle;

    //Vive le pouvoir de POO !
    Hashes *hash;
    Conversion *conv;
    Encryption *encry;
    FenHistorique *fenetreHistorique;
    GenererCle *fenetreGenererCle;


};



#endif // FENPRINCIPALE_H
