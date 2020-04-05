#ifndef CRUD_DBQUERY_H
#define CRUD_DBQUERY_H
#include "../include/include.h"

class DbQuery {
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *field;
public:
    vector<vector<string> > execQuerySelect(const char* statement, MYSQL* connection);
    int execQueryInsert(const char* statement, MYSQL* connection);
    string execQueryCount(const char* statement, MYSQL* connection);
};

#endif
