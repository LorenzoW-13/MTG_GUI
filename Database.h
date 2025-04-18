#ifndef DATABASE_H
#define DATABASE_H

#include "sqlite3.h"

#include <string>
#include <iostream>

class Database{
    public:
        //Create connection to database of given name
        Database(const std::string& name) : db(nullptr), opensuccess(false) {
            //Check that database exists and is correctly opened
            if(sqlite3_open(name.c_str(), &db) != SQLITE_OK) {
                //If errors occured, throw a message and note a failure
                std::cerr << "Error opening the database: " << sqlite3_errmsg(db) << std::endl;
            }
            else {
                //Mark the database as successfully opened
                opensuccess = true;
            }
        }

        //Delete database connection
        ~Database() {
            sqlite3_close(db);
        }

        //Return the database handler
        sqlite3* getDB() {
            return db;
        }

        //Return db state
        bool state() {
            return opensuccess;
        }

    private:
        sqlite3* db;
        bool opensuccess;

}; //Database


#endif