#ifndef CRUD_CATEGORY_H
#define CRUD_CATEGORY_H
#include "../../database/DbQuery.cpp"

class Category{
public:
    Category() {}
    int createCategory(Node* node);
    vector<vector<string> > getCategoryList(Node* node);
    string countCategory(Node* node);
    vector<vector<string> > getSubCategoryList(Node* node);
};

#endif
