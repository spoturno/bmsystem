#include <sqlite3.h>
#include <stdio.h>

int main(void) {
    
    sqlite3 *db;
    char *err_msg = 0;
    
    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    char *sql = "DROP TABLE IF EXISTS Users;" 
                "CREATE TABLE Users(Id INT, Name TEXT, Balance INT);" 
                "INSERT INTO Users VALUES(1, 'Tomas', 52642);" 
                "INSERT INTO Users VALUES(2, 'Pedro', 57127);" 
                "INSERT INTO Users VALUES(3, 'Seba', 9000);" 
                "INSERT INTO Users VALUES(4, 'Vladimir', 29000);" 
                "INSERT INTO Users VALUES(5, 'Benty', 350000);" 
                "INSERT INTO Users VALUES(6, 'Citronz', 21000);" 
                "INSERT INTO Users VALUES(7, 'Human', 41400);" 
                "INSERT INTO Users VALUES(8, 'Volkswagen', 21600);";

    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    
    return 0;
}
