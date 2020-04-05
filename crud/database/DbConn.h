#ifndef CRUD_DBCONN_H
#define CRUD_DBCONN_H
#include "../include/include.h"

class DbConn {
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL *connection, mysql;
    int state;
public:
    MYSQL* createConnection();
    MYSQL * getConnection();
    void closeConn(MYSQL* connection);
};

#endif
