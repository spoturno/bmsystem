#include <string>
#include <sqlite3.h>
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName){
    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i=0; i<argc;i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i]: "NULL");
    }
    printf("\n");
    return 0;

}

int main(int argc, char** argv){
    sqlite3 *DB;
    char* messageError;
    int exit = sqlite3_open("example.db", &DB);
    string query = "SELECT * FROM USER;";

    printf("STATE OF TABLE BEFORE INSERT\n");

    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    string sql("INSERT INTO USER VALUES(1, 'BILL', 'GATES', 30, 'PALO ALTO', 1000.0);"
               "INSERT INTO USER VALUES(2, 'STEVE', 'FAKE', 20, 'SEATTLE', 300.2);"
               "INSERT INTO USER VALUES(3, 'TOMAS', 'SPOTURNO', 20, 'MVD', 4500.2);");

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if(exit != SQLITE_OK){
        fprintf(stderr, "Error Insert");
        sqlite3_free(messageError);
    }else
        printf("Records created Successfully!\n");

    printf("STATE OF TABLE AFTER INSERT\n");
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
    sql = "DELETE FROM USER WHERE ID = 2;";
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if(exit != SQLITE_OK){
        fprintf(stderr, "Error DELETE");
        sqlite3_free(messageError);
    }else
        printf("Record deleted Seccessfully!");
    printf("STATE OF TABLE AFTER DELETE OF ELEMENT\n");
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

    sqlite3_close(DB);

    return(0);
    
}


