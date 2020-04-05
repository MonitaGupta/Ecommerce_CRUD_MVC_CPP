#ifndef CRUD_PRODUCTCONTROLLER_H
#define CRUD_PRODUCTCONTROLLER_H
#include "../ecommerce/product/Product.cpp"
#include "../include/node.h"

class ProductController {
    NodeProduct * obj;
    Product * prodObj;
public:
    ProductController(NodeProduct * obj) {
        this->obj = obj;
    }
    void execInsertReq(NodeProduct * obj);
};

#endif
