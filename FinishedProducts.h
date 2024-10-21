#ifndef FINISHEDPRODUCTS_H
#define FINISHEDPRODUCTS_H

#include <vector>
#include <fstream>
#include <iostream>

class FinishedProducts {
    std::vector<int> products;

public:
    void addProduct(int product) {
        products.push_back(product);
    }

    void showProducts() const {
        std::cout << "Finished Products:\n";
        for (int product : products) {
            std::cout << product << "\n";
        }
    }

    void saveProducts() const {
        std::ofstream outFile("products.txt");
        for (int product : products) {
            outFile << product << "\n";
        }
    }

    void loadProducts() {
        std::ifstream inFile("products.txt");
        if (inFile) {
            int product;
            while (inFile >> product) {
                products.push_back(product);
            }
        }
    }
};

#endif // FINISHEDPRODUCTS_H
