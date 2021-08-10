#include <stdio.h>
#include <sqlite3.h>
#include <stdlib.h>
#include "./db.h"

void createDatabase(){
    sqlite3 *db;
    char *err_msg = 0;
    int rc = sqlite3_open("bmsdata.db", &db);
    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return;
    }

    char *sql = "DROP TABLE IF EXISTS Users;"
                "CRATE TABLE Users(Id INT, Name TEXT, Age INT, Balance INT)";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

    if(rc != SQLITE_OK){
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return;
    }
    sqlite3_close(db);
    return;
}

User getUserDatabase(ArregloChars acc){
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;
    int rc = sqlite3_open("bmsdata.db", &db);

    if(rc != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }

    char *sql = "SELECT Accont FROM Users WHERE Account = @acc";

    if(rc == SQLITE_OK){
        int accx = sqlite3_bind_parameter_index(res, "@acc");
        int value = 3;
        sqlite3_bind_int(res, acc, value);
    }else
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));

    int step = sqlite3_step(res);
    if(step == SQLITE_ROW){
        printf("%s:", sqlite3_column_text(res, 0));
        printf("%s:\n", sqlite3_column_text(res, 1));
    }

    //return the user with the acc form the request
    sqlite3_finalize(res);
    sqlite3_close(db);


}
