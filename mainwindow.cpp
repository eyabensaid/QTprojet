#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>
#include <QSqlQuery>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->LINE_CIN->setValidator(new QIntValidator(100, 99999999, this));
    ui->tab_client->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_B_ajouter_clicked()
{
    int cin=ui->LINE_CIN->text().toInt();
    QString nom =ui->LINE_NOM->text();
    QString prenom =ui->LINE_PRENOM->text();
    Client C(cin,nom,prenom);
bool test=C.ajouter();
if (test)
{
    QMessageBox::information(nullptr, QObject::tr("OK"),
                          QObject::tr("Ajout effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_client->setModel(C.afficher());

          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                          QObject::tr("Ajout non effectué.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supp_clicked()
{
    Client C1; C1.setcin(ui->LINE_C->text().toInt());
    bool test=C1.supprimer(C1.getcin());

    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                              QObject::tr(" suppression effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
               ui->tab_client->setModel(C1.afficher());

              }
              else
                  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("supprission non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

    }



void MainWindow::on_pb_modif_clicked()
{


    Client C2;
        int cin=ui->LINE_C->text().toInt();
        QString nom=ui->LINE_N->text();
        QString prenom=ui->LINE_P->text();

         bool test=C2.Modifier(cin,nom,prenom);
         if (test){
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("modifier successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_client->setModel(C2.afficher());

         }
         else
         {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("modifier failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}

    }





