# include <iostream>
# include <string>
#include <vector>

using namespace std;

// Product class representing any item of any ECommerce.
class Product {
    public:
        string name;
        double price;
    
    Product(string name, double price) {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {

    private:
        vector<Product*> products;

    public:
        void addProduct(Product* p) {
            products.push_back(p);
        }

        const vector<Product*>& getProducts() const {
            return products;
        }

        // 1. CALCULATE TOTAL PRICE OF PRODUCTS IN THE CART
        double calculateTotalPrice() {
            double total = 0;
            for (auto p : products) {
                total += p->price;
            }
            return total;
        }

        // 2. PRINT INVOICE OF PRODUCTS IN THE CART
        

};



int main() {
   




    return 0;
}