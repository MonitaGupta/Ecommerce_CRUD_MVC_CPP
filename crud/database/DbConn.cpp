#include "DbConn.h"

MYSQL* DbConn::createConnection() {
    mysql_init(&mysql);
    return connection = mysql_real_connect(&mysql,
                                    "localhost",
                                    "root",
                                    "Angel123#",
                                    "ecommerce",
                                    0,
                                    0,
                                    0);
}

MYSQL* DbConn::getConnection() {
    MYSQL* connection = createConnection();
    return connection;
}

void DbConn::closeConn(MYSQL* connection){
    mysql_close(connection);
}