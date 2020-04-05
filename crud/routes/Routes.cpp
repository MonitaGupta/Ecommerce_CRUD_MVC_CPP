#include "Routes.h"
#include "../controllers/CategoryController.cpp"
#include "../controllers/ProductController.cpp"
#include "../include/node.h"

void Routes::createCategory(Node * obj) {
    CategoryController * createObj = new CategoryController(obj);
    createObj->execInsertReq(obj);
}

vector<vector<string> > Routes::selectAllCategory(Node *obj) {
    CategoryController * createObj = new CategoryController(obj);
    return createObj->execListAll(obj);
}

string Routes::countCategories(Node *obj) {
    CategoryController * createObj = new CategoryController(obj);
    return createObj->execCountReq(obj);
}

vector<vector<string> > Routes::selectSubCategory(Node *obj) {
    CategoryController * createObj = new CategoryController(obj);
    return createObj->execSubCategoryList(obj);
}

void Routes::addProduct(NodeProduct* obj) {
    ProductController * createObj = new ProductController(obj);
    createObj->execInsertReq(obj);
}
