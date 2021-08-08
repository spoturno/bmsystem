#include <sqlite3.h>
#include <stdio.h>

int callback(void*, int, char**, char**);

int main(void){
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;

    int rc = sqlite3_open("test.db", &db);

    if(rc != SQLITE_OK ){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    char *sql = "SELECT Id, Balance FROM Users WHERE Id = @id";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if(rc == SQLITE_OK){
        int idx = sqlite3_bind_parameter_index(res, "@id");
        int value = 3;
        sqlite3_bind_int(res, idx, value);
    }else{
        fprintf(stderr, "Failed to executre statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    if(step == SQLITE_ROW){
        printf("%s: ", sqlite3_column_text(res, 0));
        printf("%s:\n ", sqlite3_column_text(res, 1));
    }

    sqlite3_finalize(res);
    sqlite3_close(db);




    // handles if there is more than 1 colum
    //rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
/*
    if(rc != SQLITE_OK){
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        return 1;
    }

    sqlite3_close(db);
    return 0;
}

int callback(void * NotUsed, int argc, char **argv, char **azColName){
    NotUsed = 0;
    // argc:#colums argv:array of string representing column names
    for(int i =0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
*/




