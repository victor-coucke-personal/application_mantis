#ifndef FINISHEDPRODUCTS_H
#define FINISHEDPRODUCTS_H

#include <vector>
#include <string>

class FinishedProducts {
    std::vector<int> products;

public:
    FinishedProducts() = default;  // Inline constructor

    void addProduct(int product);
    void showProducts() const;
    void saveProducts() const;
    void loadProducts();
};

#endif // FINISHEDPRODUCTS_H
