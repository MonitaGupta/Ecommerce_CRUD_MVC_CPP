#ifndef CRUD_NODE_H
#define CRUD_NODE_H

class Node {
public:
    string category;
    string parent;
    string left;
    string right;
    string id;
    MYSQL* connection;

    Node(string category, string parent, string left, string right, MYSQL* connection, string id) {
        this->category = category;
        this->parent = parent;
        this->left = left;
        this->right = right;
        this->connection = connection;
        this->id = id;
    }
};


class NodeProduct {
public:
    string category;
    string name;
    string id;
    MYSQL* connection;

    NodeProduct(string categoryId, string name, string id, MYSQL* connection) {
        this->category = categoryId;
        this->name = name;
        this->id = id;
        this->connection = connection;
    }
};
#endif
