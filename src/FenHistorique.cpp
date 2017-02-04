#include "FenHistorique.h"


using namespace std;

FenHistorique::FenHistorique(QWidget *parent) : QDialog(parent)
{
    conv = new Conversion();

    textEdit = new QTextEdit;   //QTextEdit pour mettre l'historique
    textEdit->setReadOnly(true); //lecture seul

    boutonAttraperEntrer = new QPushButton(tr("Attraper Entrer"));
    boutonAttraperSortie = new QPushButton(tr("Attraper Sortie"));
    boutonAttraperTous = new QPushButton(tr("Attraper Tous"));
    boutonVider = new QPushButton(tr("&Vider"));
    boutonVider->setEnabled(false);

    QHBoxLayout *layoutBouton = new QHBoxLayout; //On défini le layout qui contiendra les différents boutons
    layoutBouton->addWidget(boutonAttraperEntrer);
    layoutBouton->addWidget(boutonAttraperSortie);
    layoutBouton->addWidget(boutonAttraperTous);
    layoutBouton->addWidget(boutonVider);

    QVBoxLayout *layout = new QVBoxLayout; //On défini le layout qui contient le QtextEdit et l'autre layout des boutons
    layout->addWidget(textEdit);
    layout->addLayout(layoutBouton);
    setLayout(layout); //On le défini en tant que layout principale


    QSettings settings(tr("Crypo", "Qt apps"));
    QString msg64 = settings.value("Historique").toString();

    string msg = conv->Base64Decode(msg64);
    textEdit->setText(QString::fromStdString(msg));

    setWindowTitle(tr("Historique"));

    //Gestion des signaux et des slots
    connect(boutonAttraperEntrer, SIGNAL(clicked()), this, SLOT(attrapeEntree()));
    connect(boutonAttraperSortie, SIGNAL(clicked()), this, SLOT(attrapeSortie()));
    connect(boutonAttraperTous, SIGNAL(clicked()), this, SLOT(attrapeTous()));
    connect(boutonVider, SIGNAL(clicked()), this, SLOT(viderSlot()));
}

void FenHistorique::attrapeEntree()
{
    emit attrapeSignal("Entrée");
}

void FenHistorique::attrapeSortie()
{
    emit attrapeSignal("Sortie");
}

void FenHistorique::attrapeTous()
{
    emit attrapeSignal("Tous");
}

void FenHistorique::viderSlot()
{
    textEdit->clear();
    boutonVider->setEnabled(false);
}

void FenHistorique::fermerEvent(QCloseEvent *event)
{
    string msg = conv->Base64Encode(textEdit->toPlainText());

    QSettings settings(tr("Crypo", "Qt apps"));
    settings.setValue("Historique", QString::fromStdString(msg));
    event->accept();
}

