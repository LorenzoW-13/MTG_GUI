//Class to manage the operations on the database
#ifndef DBOP_H
#define DBOP_H

#include "Database.h"
#include "DBStrings.h"

class DBOp {
    public: 
        DBOp(Database& db);
        ~DBOP() {};

        int createTable();

    private:
        Database& db_;
}; //DBOperations

#endif