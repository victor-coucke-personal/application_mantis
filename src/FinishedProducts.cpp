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
    std::ofstream outFile("../products.txt");
    for (int product : products) {
        outFile << product << "\n";
    }
}

void FinishedProducts::loadProducts() {
    int product;
    // Open the file "products.txt" for reading
    std::ifstream inputFile("../products.txt");
    // Read a single integer from the file
    inputFile >> product;

    // Check if the reading was successful
    if (inputFile.fail()) {
        std::cout << "No previous result found" << "\n";
    }
    else {
        std::cout << "previous processed result found: " << product << "\n";
        products.push_back(product);
    }

    // Close the file
    inputFile.close();

}

