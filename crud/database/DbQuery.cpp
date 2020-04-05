#include "DbQuery.h"

int DbQuery::execQueryInsert(const char* statement, MYSQL* connection) {
    cout << statement << endl;
    int state = mysql_query(connection, statement);
    if (state != 0){
        return -1;
    }
    cout << "Insert completed" << endl;
    return 0;
}

vector<vector<string> > DbQuery::execQuerySelect(const char* statement, MYSQL* connection) {
    vector<string> rows;
    vector<vector<string> > cols;

    if(connection==NULL) {
        cout << "connection error" << endl;
        return cols;
    }

    int state = mysql_query(connection, statement);
    if (state != 0) {
        cout << (mysql_error(connection)) << endl;
        return cols;
    }

    result = mysql_store_result(connection);
    int count = mysql_num_rows(result);

    while ( ( field = mysql_fetch_field(result)) != NULL){
        rows.push_back(field->name);
    }
    cols.push_back(rows);
    rows.clear();

    int fieldCount = mysql_num_fields(result);
    int testCount = 0;
    while ( ( row = mysql_fetch_row(result)) != NULL) {
        while(testCount < fieldCount) {
            if(row[testCount]==NULL){
                rows.push_back(" ");
                testCount++;
                continue;
            }
            rows.push_back(row[testCount]);
            testCount++;
        }
        cols.push_back(rows);
        rows.clear();
        testCount=0;
    }
    mysql_free_result(result);
    return cols;
}

string DbQuery::execQueryCount(const char* statement, MYSQL* connection) {
    if(connection==NULL) {
        cout << "connection error" << endl;
        return NULL;
    }

    int state = mysql_query(connection, statement);
    if (state != 0) {
        cout << (mysql_error(connection)) << endl;
        return NULL;
    }

    result = mysql_store_result(connection);
    mysql_num_rows(result);
    row = mysql_fetch_row(result);
    return row[0];
}
