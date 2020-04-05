#include <iostream>
#include "database/DbConn.cpp"
#include "routes/Routes.cpp"
using namespace std;

MYSQL *initialConnection(DbConn connect) {
    MYSQL *connection = connect.getConnection();
    return connection ? connection : NULL;
}

void closeConnection( MYSQL *connection) {
    if(connection)
        mysql_close(connection);
}

int main() {
    DbConn connect;
    MYSQL* connection = initialConnection(connect);

    if(!connection)
        return -1;

    cout << "\n What should I do?" << endl;
    cout << "1. INSERT CATEGORY" << endl;
    cout << "2. RETRIEVE LIST OF ALL CATEGORY" << endl;
    cout << "3. COUNT CATEGORIES" << endl;
    cout << "4. RETRIEVE ALL SUBCATEGORY OF CHOSEN CATEGORY" << endl;
    cout << "5. INSERT PRODUCT" << endl;
    cout << "6. LIST PRODUCTS" << endl;

    Node* node;
    NodeProduct * nodeProd;
    Routes * rObj = new Routes();;
    int choice;
    cin >> choice;
    switch(choice) {
        case 1:
            {
                string category, parent, left, right, id;

                cout << "Id" << endl;
                cin >> id;
                cout << "CATEGORY NAME" << endl;
                cin >> category;
                cout << "PARENT CATEGORY ID" << endl;
                cin >> parent;
                cout << "ENTER LEFT BOUNDARY" << endl;
                cin >> left;
                cout << "ENTER RIGHT BOUNDARY" << endl;
                cin >> right;

                node = new Node(category, parent, left, right, connection, id);
                rObj->createCategory(node);
                break;
            }

        case 2:
            {
                cout << "Retrieving list of all categories" << endl;
                node = new Node("NULL", "NULL", "NULL", "NULL", connection, "NULL");
                rObj->selectAllCategory(node);
                break;
            }

        case 3:
            {
                cout << "Total category count" << endl;
                node = new Node("NULL", "NULL", "NULL", "NULL", connection, "NULL");
                cout << "count = " << rObj->countCategories(node) << endl;
                break;
            }
        case 4:
            {
                cout << "Enter Category: " << endl;
                string category;
                cin >> category;
                node = new Node(category, "NULL", "NULL", "NULL", connection, "NULL");
                rObj->selectSubCategory(node);
                break;
            }

        case 5:
            {
                cout << "Insert new product" << endl;
                string product, categoryId, id;
                cin >> id >> categoryId >> product;
                nodeProd = new NodeProduct(categoryId, product, id, connection);
                rObj->addProduct(nodeProd);
                break;
            }

        case 6:
            {
                cout << "Display list of products" << endl;
                nodeProd = new NodeProduct("NULL", "NULL", "NULL", connection);
                break;
            }
        default:
            break;
    }

    closeConnection(connection);
    cout << std::flush;
    return 0;
}