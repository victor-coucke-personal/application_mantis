#include "FinishedProducts.h"
#include <fstream>
#include <iostream>

void FinishedProducts::addProduct(int product) {
    products.push_back(product);
}

void FinishedProducts::showProducts() const {
    std::cout << "Finished Products:\n";
    for (int product : products) {
        std::cout << product << "\n";
    }
}

void FinishedProducts::saveProducts() const {
    std::ofstream outFile("products.txt");
    for (int product : products) {
        outFile << product << "\n";
    }
}

void FinishedProducts::loadProducts() {
    std::ifstream inFile("products.txt");
    if (inFile) {
        int product;
        while (inFile >> product) {
            products.push_back(product);
        }
    }
}
