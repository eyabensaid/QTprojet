#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlError>
#include<QObject>
Client::Client()
{
cin=0; nom=""; prenom="";
}

Client::Client(int cin,QString nom,QString prenom )
{this->cin=cin; this->nom=nom; this->prenom=prenom;}

int Client:: getcin(){return cin;}
QString Client:: getnom(){return nom;}
QString Client::getprenom(){return prenom;}
void Client::setcin(int cin){this->cin=cin;}
void Client::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
bool Client::ajouter()
{


    QSqlQuery query;

      QString cin_string=QString::number(cin);

    query.prepare("INSERT INTO CLIENT(nom, prenom,cin)"
                  "VALUES (:nom, :prenom,:cin)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":cin",cin);

    qDebug()<<query.lastError();


    return query.exec();


}
bool Client::supprimer(int cin)
{
    QSqlQuery query;

      QString cin_string=QString::number(cin);

    query.prepare("Delete from client where cin=:cin");
    query.bindValue(0,cin);

    qDebug()<<query.lastError();


    return query.exec();


}
 QSqlQueryModel* Client::afficher()
 {
    QSqlQueryModel* model=new QSqlQueryModel();


   model->setQuery("SELECT* FROM client");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));



    return model;
 }

    bool Client::Modifier(int cin,QString nom,QString prenom)
    {
        QSqlQuery query;

        QString cin_string =QString::number(cin);
        query.prepare("UPDATE Client SET  nom=:nom ,prenom=:prenom WHERE cin=:cin");

        query.bindValue(":cin", cin_string);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);

        return  query.exec();




 }
