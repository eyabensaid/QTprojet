#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("eya");//inserer nom de l'utilisateur
db.setPassword("eya");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

else
    throw QString("erreur parametres");




    return  test;
}