#include "FenPrincipale.h"
#include <string.h>

using namespace std;
using namespace CryptoPP;

FenPrincipale::FenPrincipale()
{
    onglets = new QTabWidget(this);
    onglets ->setGeometry(0,0,700,580);

    //Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    /* Attention ! A voir : utiliser qu'une seule page pour une propreté du programme
      Les différentes types (hash,encryption,encodage) se feront uniquement sur la même page !
      Evite donc une répition de code inutile
      */

    pageCrypter = new QWidget;


    //Page 1 : Page Cryptage

    layout = new QHBoxLayout; // Définition de la première ligne avec le Label "Cryptage" et la QComboBox

    labelCryptage = new QLabel("Cryptage : "); //Définition du Label

    QStringList listeCryptage; //On déclare notre petite liste d'algorithme
    listeCryptage << "########## Hashing ##########"
    << "Adler32" << "CRC32" << "MD2" << "MD4" << "MD5"
    << "RIPEMD-128"
    << "RIPEMD-160" << "RIPEMD-320"
    << "SHA-1" << "SHA-224" << "SHA-256" << "SHA-384"
    << "SHA-512" << "Tiger" << "Whirlpool"
    << "########## Encryption ##########"
    << "AES (Encryption)" << "AES (Décryption)" << "Blowfish (Encryption)" << "Blowfish (Décryption)" << "Camellia (Encryption)" << "Camellia (Décryption)"
    << "CAST128 (Encryption)" << "CAST128 (Décryption)" << "CAST256 (Encryption)" << "CAST256 (Décryption)" << "DES (Encryption)" << "DES (Décryption)"
    << "DES 2 (Encryption)" << "DES 2 (Décryption)" << "DES 3 (Encryption)" << "DES 3 (Décryption)" << "DES X3 (Encryption)" << "DES X3 (Décryption)" << "GOST (Encryption)"
    << "GOST (Décryption)" << "IDEA (Encryption)" << "IDEA (Décryption)" << "MARS (Encryption)" << "MARS (Décryption)" << "Panama (Encryption)" << "Panama (Décryption)" << "RC2 (Encryption)" << "RC2 (Décryption)"
    << "RC5 (Encryption)" << "RC5 (Décryption)" << "RC6 (Encryption)" << "RC6 (Rivest Cipher 6 - Décryption)" << "SAFER_K (Encryption)" << "SAFER_K (Décryption)"
    << "SAFER_SK (Encryption)" << "SAFER_SK (Décryption)" << "Salsa20 (Encryption)" << "Salsa20 (Décryption)" << "SEAL (Encryption)" << "SEAL (Décryption)" << "SEED (Encryption)" << "SEED (Décryption)" << "Serpent (Encryption)" << "Serpent (Décryption)" << "SHACAL2 (Encryption)" << "SHACAL2 (Décryption)"
    << "SHARK (Encryption)" << "SHARK (Décryption)" << "SKIPJACK (Encryption)" << "SKIPJACK (Décryption)" << "Sosemanuk (Encryption)" << "Sosemanuk (Décryption)" << "Square (Encryption)" << "Square (Décryption)"
    << "TEA (Encryption)" << "TEA (Décryption)" << "ThreeWay (Encryption)" << "ThreeWay (Décryption)" << "Twofish (Encryption)" << "Twofish (Décryption)"
    << "XSalsa20 (Encryption)" << "XSalsa20 (Décryption)" << "XTEA (Encryption)" << "XTEA (Décryption)"
    << "########## Conversions ##########"
    << "Base32 Encodage" << "Base32 Décodage" << "Base64 Encodage" << "Base64 Décodage" << "Hexadécimale Encodage" << "Hexadécimale Décodage" << "Reverse String" << "ROT13 Encode"
    << "URLEncode" << "URLDecode" << "UUEncode" << "UUDecode";

    listeCryptage1 = new QComboBox; //ComBoBox pour choisir le type de cryptage
    listeCryptage1->addItems(listeCryptage); // On rajoute dans notre QComboBox la liste de cryptage

    layout->addWidget(labelCryptage);
    layout->addWidget(listeCryptage1);

    layout2 = new QHBoxLayout; //Ce layout contient les deux QTextEdit qui afficheront le résultat du cryptage

    champNonCrypter = new QTextEdit;
    champCrypter = new QTextEdit;
    champNonCrypter->setAcceptRichText(true);
    champCrypter->setReadOnly(true);
    layout2->addWidget(champNonCrypter);
    layout2->addWidget(champCrypter);

    layout3 = new QHBoxLayout; //Ce layout contient les différents boutons tels que "Crypter"

    labelCle = new QLabel("Clé : ");
    ligneCle = new QLineEdit;
    ligneCle->setReadOnly(true);
    labelCle->setAlignment(Qt::AlignLeft);
    ligneCle->setAlignment(Qt::AlignLeft);
    boutonGenererCle = new QPushButton("##");
    boutonGenererCle->setToolTip("Générer Clé !");
    boutonGenererCle->setEnabled(false);

    boutonOutils = new QPushButton("Outils"); //Ce bouton est un peu particulier : il est sous la forme d'une QComboBox : il permet de choisir grâve à un mini menu d'autre action (mise en maj/min, l'historique....)
    boutonOutils->setIcon(QIcon("img/outils.png")); //On défini une image
    boutonVider = new QPushButton("&Vider");
    boutonVider->setIcon(QIcon("img/vider.png"));
    boutonEchanger = new QPushButton("&Echanger");
    boutonEchanger->setIcon(QIcon("img/echanger.png"));
    boutonCopier = new QPushButton("&Copier");
    boutonCopier->setIcon(QIcon("img/copier.png"));
    boutonQuitter = new QPushButton("&Quitter");
    boutonQuitter->setIcon(QIcon("img/quitter.png"));

    layout3->addWidget(labelCle); //On rajoute au layout les differents boutons
    layout3->addWidget(ligneCle);
    layout3->addWidget(boutonOutils);
    layout3->addWidget(boutonGenererCle);
    layout3->addWidget(boutonVider);
    layout3->addWidget(boutonEchanger);
    layout3->addWidget(boutonCopier);
    layout3->addWidget(boutonQuitter);
    layout3->setAlignment(Qt::AlignRight);

    layoutPrincipale = new QVBoxLayout; //On défini un layout principale, auquel on rajoute les 3 autres layouts
    layoutPrincipale->addLayout(layout);
    layoutPrincipale->addLayout(layout2);
    layoutPrincipale->addLayout(layout3);

    setLayout(layoutPrincipale); //Et on le défini en tant que layout principale
    pageCrypter->setLayout(layoutPrincipale);

    champNonCrypterActiver(false);
    minuscule = new QAction(tr("Rendu en minuscule"),this);
    minuscule->setIcon(QIcon("img/minuscule.png"));
    minuscule->setCheckable(true);

    historique = new QAction(tr("Historique"),this);
    historique->setIcon(QIcon("img/historique"));
    genererCle = new QAction(tr("&Générer clé"), this);
    genererCle->setIcon(QIcon("img/gen.png"));

    QMenu *menu = new QMenu(this);
    menu->addAction(minuscule);
    menu->addAction(historique);
    menu->addAction(genererCle);
    boutonOutils->setMenu(menu);

    lireReglages();




    onglets->addTab(pageCrypter,"Crypter");

    //Connections des signaux et des slots

    connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(champNonCrypter,SIGNAL(textChanged()),this,SLOT(selectionCrypt()));
    connect(boutonVider,SIGNAL(clicked()),this,SLOT(vider())); //Connection du bouton Vider au SLOT vider
    connect(boutonEchanger,SIGNAL(clicked()),this,SLOT(echanger())); //Connection du bouton Echanger au SLOT Echanger
    connect(boutonCopier,SIGNAL(clicked()),this,SLOT(copier())); //Connection du bouton Copier au SLOT Copier
    connect(minuscule,SIGNAL(triggered()),this,SLOT(selectionCrypt()));
    connect(genererCle, SIGNAL(triggered()), this, SLOT(genererCleSlot()));
    connect(boutonGenererCle,SIGNAL(clicked()),this,SLOT(genererCleOptSlot()));
    connect(historique, SIGNAL(triggered()), this, SLOT(historiqueSlot()));


}

 void FenPrincipale::selectionCrypt()
{

    conv = new Conversion();
    hash = new Hashes();
    encry = new Encryption();

    functions fun = functions(listeCryptage1->currentIndex());

    if (fun != separateur && fun != separateur1 && fun != separateur2)
    {
        if (fun > separateur1 && fun < separateur2)
        {
            ligneCle->setReadOnly(false);
            boutonGenererCle->setEnabled(true);

            if (ligneCle->text().isEmpty())
            {
                champCrypter->setText("Merci d'écrire une clé !");
                return;
            }
        }
        else
        {

            ligneCle->setReadOnly(true);
            boutonGenererCle->setEnabled(false);
        }

        if (!champNonCrypter->toPlainText().isEmpty())
        {
            string message;

            switch (fun)
            {
            case separateur:
                break;
            case Adler32:
                message = hash->Adler32Fonction(champNonCrypter->toPlainText());
                break;
            case CRC32:
                message = hash->Crc32Fonction(champNonCrypter->toPlainText());
                break;
            case MD2:
                message = hash->Md2Fonction(champNonCrypter->toPlainText());
                break;
            case MD4:
                message = hash->Md4Fonction(champNonCrypter->toPlainText());
                break;
            case MD5:
                message = hash->Md5Fonction(champNonCrypter->toPlainText());
                break;
            case RIPEMD128:
                message = hash->Ripemd128Fonction(champNonCrypter->toPlainText());
                break;
            case RIPEMD160:
                message = hash->Ripemd160Fonction(champNonCrypter->toPlainText());
                break;
            case RIPEMD320:
                message = hash->Ripemd320Fonction(champNonCrypter->toPlainText());
                break;
            case SHA1:
                message = hash->Sha1Fonction(champNonCrypter->toPlainText());
                break;
            case SHA224:
                message = hash->Sha224Fonction(champNonCrypter->toPlainText());
                break;
            case SHA256:
                message = hash->Sha256Fonction(champNonCrypter->toPlainText());
                break;
            case SHA384:
                message = hash->Sha384Fonction(champNonCrypter->toPlainText());
                break;
            case SHA512:
                message = hash->Sha512Fonction(champNonCrypter->toPlainText());
                break;
            case Tiger:
                message = hash->TigerFonction(champNonCrypter->toPlainText());
                break;
            case Whirlpool:
                message = hash->WhirlpoolFonction(champNonCrypter->toPlainText());
                break;
            case separateur1:
                break;
            case AES:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "AES", true);
                break;
            case AES_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "AES", false);
                break;
            case Blowfish:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Blowfish", true);
                break;
            case Blowfish_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Blowfish", false);
                break;
            case Camellia:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Camellia", true);
                break;
            case Camellia_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Camellia", false);
                break;
            case CAST128:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "CAST128", true);
                break;
            case CAST128_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "CAST128", false);
                break;
            case CAST256:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "CAST256", true);
                break;
            case CAST256_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "CAST256", false);
                break;
            case DES:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES", true);
                break;
            case DES_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES", false);
                break;
            case DES_EDE2:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES_EDE2", true);
                break;
            case DES_EDE2_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES_EDE2", false);
                break;
            case DES_EDE3:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES_EDE3", true);
                break;
            case DES_EDE3_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES_EDE3", false);
                break;
            case DES_XEX3:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES_XEX3", true);
                break;
            case DES_XEX3_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "DES_XEX3", false);
                break;
            case GOST:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "GOST", true);
                break;
            case GOST_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "GOST", false);
                break;
            case IDEA:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "IDEA", true);
                break;
            case IDEA_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "IDEA", false);
                break;
            case MARS:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "MARS", true);
                break;
            case MARS_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "MARS", false);
                break;
            case Panama:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Panama", true);
                break;
            case Panama_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Panama", false);
                break;
            case RC2:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "RC2", true);
                break;
            case RC2_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "RC2", false);
                break;
            case RC5:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "RC5", true);
                break;
            case RC5_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "RC5", false);
                break;
            case RC6:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "RC6", true);
                break;
            case RC6_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "RC6", false);
                break;
            case SAFER_K:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SAFER_K", true);
                break;
            case SAFER_K_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SAFER_K", false);
                break;
            case SAFER_SK:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SAFER_SK", true);
                break;
            case SAFER_SK_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SAFER_SK", false);
                break;
            case Salsa20:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Salsa20", true);
                break;
            case Salsa20_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Salsa20", false);
                break;
            case SEAL:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SEAL", true);
                break;
            case SEAL_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SEAL", false);
                break;
            case SEED:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SEED", true);
                break;
            case SEED_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SEED", false);
                break;
            case Serpent:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Serpent", true);
                break;
            case Serpent_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Serpent", false);
                break;
            case SHACAL2:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SHACAL2", true);
                break;
            case SHACAL2_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SHACAL2", false);
                break;
            case SHARK:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SHARK", true);
                break;
            case SHARK_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SHARK", false);
                break;
            case SKIPJACK:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SKIPJACK", true);
                break;
            case SKIPJACK_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "SKIPJACK", false);
                break;
            case Sosemanuk:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Sosemanuk", true);
                break;
            case Sosemanuk_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Sosemanuk", false);
                break;
            case Square:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Square", true);
                break;
            case Square_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Square", false);
                break;
            case TEA:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "TEA", true);
                break;
            case TEA_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "TEA", false);
                break;
            case ThreeWay:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "ThreeWay", true);
                break;
            case ThreeWay_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "ThreeWay", false);
                break;
            case Twofish:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Twofish", true);
                break;
            case Twofish_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "Twofish", false);
                break;
            case XSalsa20:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "XSalsa20", true);
                break;
            case XSalsa20_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "XSalsa20", false);
                break;
            case XTEA:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "XTEA", true);
                break;
            case XTEA_D:
                message = encry->encryption(ligneCle->text(), champNonCrypter->toPlainText(), "XTEA", false);
                break;
            case separateur2:
                break;
            case Base32Encode:
                message = conv->Base32Encode(champNonCrypter->toPlainText());
                break;
            case Base32Decode:
                message = conv->Base32Decode(champNonCrypter->toPlainText());
                break;
            case Base64Encode:
                message = conv->Base64Encode(champNonCrypter->toPlainText());
                break;
            case Base64Decode:
                message = conv->Base64Decode(champNonCrypter->toPlainText());
                break;
            case HexEncode:
                message = conv->HexEncode(champNonCrypter->toPlainText());
                break;
            case HexDecode:
                message = conv->HexDecode(champNonCrypter->toPlainText());
                break;
            case Reverse:
                message = conv->Reverse(champNonCrypter->toPlainText());
                break;
            case Rot13Encode:
                message = conv->Rot13Encode(champNonCrypter->toPlainText());
                break;
            case URLEncode:
                message = conv->UrlEncodeString(champNonCrypter->toPlainText());
                break;
            case URLDecode:
                message = conv->UrlDecodeString(champNonCrypter->toPlainText());
                break;
            case UUEncode:
                message = conv->UUEncodeString(champNonCrypter->toPlainText());
                break;
            case UUDecode:
                message = conv->UUDecodeString(champNonCrypter->toPlainText());
                break;
            }
            if (minuscule->isChecked())
                champCrypter->setText(QString::fromStdString(message).toLower());
            else
                champCrypter->setText(QString::fromStdString(message));

            champNonCrypterActiver(true);
        }
        else
        {
            champCrypter->setText("Merci d'écrire quelque chose");
            champNonCrypterActiver(false);
        }
    }
    else
    {
        champCrypter->setText("Merci de choisir un type de cryptage/encodage dans la liste déroulante");
        champNonCrypterActiver(false);


        ligneCle->setReadOnly(true);
        boutonGenererCle->setEnabled(false);
    }

}

void FenPrincipale::vider()
{
    champNonCrypter->clear();
    champCrypter->clear();
    ligneCle->clear();
}

void FenPrincipale::echanger()
{
    QString tmp = champNonCrypter->toPlainText();
    champNonCrypter->setText(champCrypter->toPlainText());
    champCrypter->setText(tmp);
}

void FenPrincipale::copier()
{
    champCrypter->selectAll();
    champCrypter->copy();
}

void FenPrincipale::champNonCrypterActiver(bool statut) //Permet de rendre dispo ou non les autres
{
    boutonVider->setEnabled(statut);
    boutonEchanger->setEnabled(statut);
    boutonCopier->setEnabled(statut);
}

void FenPrincipale::historiqueSlot()
{

        fenetreHistorique = new FenHistorique(this); //Grace à la POO, on a défini notre fenetre Historique
        fenetreHistorique->setWindowIcon(QIcon("img/historique.png"));
        QPoint p = pos();  //On défini une position lorsque la fenêtre s'ouvre
        p.rx() += 480;

        connect(fenetreHistorique, SIGNAL(attrapeSignal(QString)), this, SLOT(attraperSignal(QString)));

        fenetreHistorique->move(p);
        fenetreHistorique->setFixedSize(400, 480);
        fenetreHistorique->show();
}

void FenPrincipale::attraperSignal(QString fun)
{
    int fonctionActuel = listeCryptage1->currentIndex();

        if (!champNonCrypter->toPlainText().isEmpty())
        {
            QString texteFinal;
            if (!fenetreHistorique->textEdit->toPlainText().isEmpty())
                texteFinal += fenetreHistorique->textEdit->toPlainText();

            if (fun == "Entrée")
            {
                if (fonctionActuel > 16 && fonctionActuel < 69)
                    texteFinal += "\nEntrée: " + champNonCrypter->toPlainText() + "\nClé: " + ligneCle->text() + "\n";
                else
                    texteFinal += "\nEntrée: " + champNonCrypter->toPlainText() + "\n";
            }

            else if (fonctionActuel != 0 && fonctionActuel != 16 && fonctionActuel != 69)
            {
                if (fun == "Sortie")
                    texteFinal += "\nSortie: " + champCrypter->toPlainText() + "\n";

                else if (fun == "Tous")
                {
                    if (fonctionActuel > 16 && fonctionActuel < 69)
                        texteFinal += "\nEntrée: " + champNonCrypter->toPlainText() + "\nClé: " + ligneCle->text() + "\nSortie: " + champCrypter->toPlainText() + "\n";
                    else
                        texteFinal += "\nEntrée: " + champNonCrypter->toPlainText() + "\nSortie: " + champCrypter->toPlainText() + "\n";
                }
            }

            fenetreHistorique->textEdit->setText(texteFinal);
            fenetreHistorique->boutonVider->setEnabled(true);
        }
}

void FenPrincipale::genererCleSlot()
{
    fenetreGenererCle = new GenererCle(this);
    fenetreGenererCle->setWindowIcon(QIcon("img/gen.png"));

        if (fenetreGenererCle->exec())
        {
            QSettings settings(tr("Crypo", "Qt apps"));

            settings.setValue("GénérerClé/Minuscule", fenetreGenererCle->verifMinuscule->isChecked()); //Bien faire attention à mettre EXACTEMENT le même nom dans les différentes fonctions(slot). Sinon sa n'enregistre pas.
            settings.setValue("GénérerClé/Majuscule", fenetreGenererCle->verifMajuscule->isChecked());
            settings.setValue("GénérerClé/Chiffres", fenetreGenererCle->verifNombre->isChecked());
            settings.setValue("GénérerClé/CaractèresSpéciaux", fenetreGenererCle->verifSpecialCarac->isChecked());
            settings.setValue("GénérerClé/Longueur", fenetreGenererCle->longueur->value());
            /*
              Les valeurs sont enregistrés dans : HKEY_CURRENT_USER\Software\Crypo (pour Windows)
              Normalement pour linux c'est : $HOME/.config/Crypo
              */
        }
        }

void FenPrincipale::genererCleOptSlot()
{
    if (!ligneCle->isReadOnly())
        {
            QString cleGenerer;
            QString typeCle;
            int max, intGen;
            qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

            fenetreGenererCle = new GenererCle(this);

            if (fenetreGenererCle->verifMajuscule->isChecked())
                typeCle += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            if (fenetreGenererCle->verifMinuscule->isChecked())
                typeCle += "abcdefghijklmnopqrstuvwxyz";

            if (fenetreGenererCle->verifNombre->isChecked())
                typeCle += "0123456789";

            if (fenetreGenererCle->verifSpecialCarac->isChecked())
                typeCle += "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

            if (!typeCle.isEmpty())
            {
                max = typeCle.size();

                for (int i = 0; i < fenetreGenererCle->longueur->value() ; i++)
                {
                    intGen = (qrand() % max);
                    cleGenerer[i] = typeCle[intGen];
                }

                ligneCle->setText(cleGenerer);
            }

            else
            {
                QMessageBox::critical(this, "Erreur", "Merci de sélectionner l'alphabet à utiliser parmis les options !");
                return;
            }

        }
        else
            champCrypter->setText("Merci de sélectionner une fonction d'encryption d'abord !");
}

GenererCle::GenererCle(QWidget *parent) : QDialog(parent)
{
    verifMajuscule = new QCheckBox("Lettre Majuscule"); //On instancie les différents checkbox et les labels
    verifMinuscule = new QCheckBox("Lettre Minuscule");
    verifNombre = new QCheckBox("Chiffres");
    verifSpecialCarac = new QCheckBox("Caractères spéciaux");

    labelLongueur = new QLabel(tr("Longueur de la clé"));
    longueur = new QSpinBox;
    longueur->setMaximum(32);
    longueur->setMinimum(1);
    longueur->setValue(12);

    QGridLayout *layoutOptions = new QGridLayout; //On met nos check/label dans une grille
    layoutOptions->addWidget(verifMajuscule, 0, 0);
    layoutOptions->addWidget(verifMinuscule, 1, 0);
    layoutOptions->addWidget(verifNombre, 0, 1);
    layoutOptions->addWidget(verifSpecialCarac, 1, 1);
    layoutOptions->addWidget(labelLongueur, 2, 0);
    layoutOptions->addWidget(longueur, 2, 1);

    boutonOk = new QPushButton(tr("Appliquer"));
    boutonOk->setIcon(QIcon("img/valider.png"));
    boutonAnnuler = new QPushButton(tr("Annuler"));
    boutonAnnuler->setIcon(QIcon("img/annuler.png"));

    QHBoxLayout *layoutBouton = new QHBoxLayout; //Les boutons dans une layout horizontale
    layoutBouton->addWidget(boutonOk);
    layoutBouton->addWidget(boutonAnnuler);
    layoutBouton->setAlignment(Qt::AlignRight);

    QVBoxLayout *layout = new QVBoxLayout(); //La layout principale (verticale)
    layout->addLayout(layoutOptions);
    layout->addLayout(layoutBouton);

    QSettings settings(tr("Crypo", "Qt apps"));

    verifMajuscule->setChecked(settings.value("GénérerClé/Majuscule", true).toBool());
    verifMinuscule->setChecked(settings.value("GénérerClé/Minuscule").toBool());
    verifNombre->setChecked(settings.value("GénérerClé/Chiffres", true).toBool());
    verifSpecialCarac->setChecked(settings.value("GénérerClé/CaractèresSpéciaux").toBool());
    longueur->setValue(settings.value("GénérerClé/Longueur", 12).toInt());

    setLayout(layout); //On défini notre layout princiaple
    setWindowTitle(tr("Options Générer Clé"));

    //Gestion des SIGNALS et des SLOTS

    connect(boutonOk, SIGNAL(clicked()), this, SLOT(accept()));
    connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(reject()));
}



void FenPrincipale::lireReglages()
{
    QSettings settings(tr("Crypo", "Qt apps"));

    minuscule->setChecked(settings.value("Minuscule").toBool());
    setWindowTitle("Crypo");

}

void FenPrincipale::ecrireReglages()
{
    QSettings settings(tr("Crypo", "Qt apps"));

    settings.setValue("Minuscule", minuscule->isChecked());

}

void FenPrincipale::fermerEvent(QCloseEvent *event)
{
    ecrireReglages();
    event->accept();
}


