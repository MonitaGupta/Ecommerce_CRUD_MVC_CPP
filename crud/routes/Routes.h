#ifndef CRUD_ROUTES_H
#define CRUD_ROUTES_H
#include "../include/node.h"

class Routes {
public:
    void createCategory(Node *obj);
    void addProduct(NodeProduct * obj);
    vector<vector<string> > selectAllCategory(Node *obj);
    vector<vector<string> > selectSubCategory(Node *obj);
    string countCategories(Node *obj);
};

#endif
