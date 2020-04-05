#include "Product.h"

int Product::addProduct(NodeProduct* node) {
    DbQuery * dbquery = new DbQuery();
    string toBeReplaced = "INSERT INTO product VALUES('id','categoryId','name')";
    string id="id",parent="categoryId",name="name";
    toBeReplaced.replace(toBeReplaced.find(id),id.length(),node->id);
    toBeReplaced.replace(toBeReplaced.find(parent),parent.length(),node->category);
    toBeReplaced.replace(toBeReplaced.find(name),name.length(),node->category);

    const char * mysql_query = toBeReplaced.c_str();

    return dbquery->execQueryInsert(mysql_query, node->connection);
}

vector<vector<string> > Product::getProductList(NodeProduct* node) {

    DbQuery * dbquery = new DbQuery();
    const char * mysql_query = "select * from product";
    vector<vector<string> > data = dbquery->execQuerySelect(mysql_query, node->connection);

    for(int i=0; i<data.size(); i++){
        for(int j=0; j<data[i].size(); j++){
            cout << data[i][j] << "\t\t";
        }
        cout << endl;
    }
    return data;
}