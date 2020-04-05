#include "CategoryController.h"

void CategoryController::execInsertReq(Node *node) {
    catObj->createCategory(node);
}

vector<vector<string> > CategoryController::execListAll(Node *node) {
    return catObj->getCategoryList(node);
}

string CategoryController::execCountReq(Node *node) {
    return catObj->countCategory(node);
}

vector<vector<string> > CategoryController::execSubCategoryList(Node *node) {
    return catObj->getSubCategoryList(node);
}