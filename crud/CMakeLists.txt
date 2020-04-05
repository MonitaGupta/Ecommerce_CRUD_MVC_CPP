cmake_minimum_required(VERSION 3.14)
project(crud)

set(CMAKE_CXX_STANDARD 17)

add_executable(crud main.cpp Config/config.h include/include.h ecommerce/category/Category.cpp ecommerce/category/Category.h ecommerce/product/Product.cpp ecommerce/product/Product.h database/DbConn.cpp database/DbConn.h routes/Routes.cpp routes/Routes.h controllers/CategoryController.cpp controllers/CategoryController.h database/DbQuery.cpp database/DbQuery.h include/node.h controllers/ProductController.cpp controllers/ProductController.h)