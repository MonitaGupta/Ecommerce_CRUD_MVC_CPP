#ifndef CRUD_CATEGORYCONTROLLER_H
#define CRUD_CATEGORYCONTROLLER_H

#include "../ecommerce/category/Category.cpp"
#include "../include/node.h"

class CategoryController {
    Node * obj;
    Category * catObj;
public:
    CategoryController(Node * obj) {
        this->obj = obj;
    }
    void execInsertReq(Node * obj);
    vector<vector<string> > execListAll(Node *obj);
    string execCountReq(Node * obj);
    vector<vector<string> > execSubCategoryList(Node* obj);
};
#endif
