//SQLite test program

//Libraries
#include <iostream>
#include <cstdlib>

#include "sqlite3.h"

//Read table callback
int callback(void* data, int argc, char** argv, char** colNames) {
    for(int i = 0; i < argc; i++) {
        std::cout << colNames[i] << ": " << argv[i] << "; ";
    }

    std::cout << std::endl;

    return 0;

}

//main
int main() {
    //Database "test" handler and open operations
    sqlite3* db;
    sqlite3_open("Test/SQLite/test.db", &db);

    //Errormessage
    char* errmsg;

    //Table creation string
    const char* sql =   "CREATE TABLE IF NOT EXISTS Test ("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT, " //Entry ID
                        "name TEXT NOT NULL, " //Entry name
                        "position TEXT NOT NULL);"; //Entry position
    
    //Create table
    if(sqlite3_exec(db, sql, nullptr, nullptr, &errmsg) != SQLITE_OK) {
        std::cerr << "Error creating the table: " << errmsg << std::endl;
        return 1;
    }

    //Insert statement
    const char* sql1 =  "INSERT INTO Test (name, position) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    if(sqlite3_prepare_v2(db, sql1, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Prepare error: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    //Strings
    std::string a = "NameNumber ";
    std::string b = "PositionNumber ";

    //Bind
    for(int i = 0; i < 5; i++) {
        if(i) {
            a.pop_back();
            b.pop_back();
        }

        a += std::to_string(i);
        b += std::to_string(i);

        //Bind the name
        if(sqlite3_bind_text(stmt, 1, a.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
            std::cerr << "Binding error: " << sqlite3_errmsg(db) << std::endl;
            return 1;
        }

        //Bind the position
        if(sqlite3_bind_text(stmt, 2, b.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
            std::cerr << "Binding error: " << sqlite3_errmsg(db) << std::endl;
            return 1;
        }

        //Execute step
        if(sqlite3_step(stmt) != SQLITE_DONE) {
            std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
            return 1;
        }

        sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);

    //Select statement
    const char* sql2 =  "SELECT * FROM Test;";

    sqlite3_exec(db, sql2, callback, nullptr, &errmsg);

    std::remove("Test/SQLite/test.db");
    std::remove("Test/SQLite/Test");

    return 0;
}