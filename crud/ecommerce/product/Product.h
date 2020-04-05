#ifndef CRUD_PRODUCT_H
#define CRUD_PRODUCT_H

class Product{
public:
    Product(){}
    vector<vector<string> > getProductList(NodeProduct* node);
    int addProduct(NodeProduct* node);
};

#endif
