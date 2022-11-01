#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>
class Client
{
public:
    Client();
    Client(int,QString,QString);
    int getcin();
    QString getnom();
    QString getprenom();
    void setcin(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool Modifier(int ,QString ,QString );


private:
    int cin;
    QString nom,prenom;
};

#endif // CLIENT_H
