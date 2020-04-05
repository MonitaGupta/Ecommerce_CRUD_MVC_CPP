#include "Category.h"

string formatString(string toBeReplaced, Node* node) {
    string id="id",parent="parent",name="name",left="left",right="right";
    toBeReplaced.replace(toBeReplaced.find(id),id.length(),node->id);
    toBeReplaced.replace(toBeReplaced.find(parent),parent.length(),node->parent);
    toBeReplaced.replace(toBeReplaced.find(name),name.length(),node->category);
    toBeReplaced.replace(toBeReplaced.find(left),left.length(),node->left);
    toBeReplaced.replace(toBeReplaced.find(right),right.length(),node->right);
    return toBeReplaced;
}

int Category::createCategory(Node* node) {
    DbQuery * dbquery = new DbQuery();
    string toBeReplaced = "INSERT INTO category VALUES(id,parent,'name',left,right)";
    toBeReplaced = formatString(toBeReplaced, node);
    const char * mysql_query = toBeReplaced.c_str();

    return dbquery->execQueryInsert(mysql_query, node->connection);
}

vector<vector<string> > Category::getCategoryList(Node* node) {

    DbQuery * dbquery = new DbQuery();
    const char * mysql_query = "select * from category";
    vector<vector<string> > data = dbquery->execQuerySelect(mysql_query, node->connection);

    for(int i=0; i<data.size(); i++){
        for(int j=0; j<data[i].size(); j++){
            cout << data[i][j] << "\t\t";
        }
        cout << endl;
    }
    return data;
}

string Category::countCategory(Node* node) {
    DbQuery * dbquery = new DbQuery();
    const char * mysql_query = "select count(*) from category";
    return dbquery->execQueryCount(mysql_query, node->connection);
}

vector<vector<string> > Category::getSubCategoryList(Node* node) {
    DbQuery * dbquery = new DbQuery();
    string toBeReplaced = "SELECT node.* FROM category as node INNER JOIN category as parent ON (node.left >= parent.left AND node.left <= parent.right) WHERE parent.name='ParentName'  ORDER BY node.left;";
    string name = "ParentName";
    toBeReplaced.replace(toBeReplaced.find(name),name.length(),node->category);
    const char * mysql_query = toBeReplaced.c_str();
    vector<vector<string> > data = dbquery->execQuerySelect(mysql_query, node->connection);

    for(int i=0; i<data.size(); i++){
        for(int j=0; j<data[i].size(); j++){
            cout << data[i][j] << "\t\t";
        }
        cout << endl;
    }
    return data;
}