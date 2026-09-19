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

// Shopping cart hanling a multiple responsibility
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

        // 1. Calculate total price in cart of all products
        double calculateTotalPrice() {
            double total = 0;
            for (auto p : products) {
                total += p->price;
            }
            return total;
        }

        // 2. Violating SRP - Prints invoice (Should be in a separate class)
        void printInvoice() {
            cout << "Shopping cart Invoice\n";
            for(auto p : products) {
                cout << p->name << " - Rs " << p->price << endl; 
            }
            cout << "Total: Rs " << calculateTotalPrice() << endl;
        }

        // 3. Violating SRP - Saves to DB (Should be in a separate class)
        void saveToDatabase () {
            cout << "Saving shopping cart to database.." << endl; 
        }
};



int main() {

    ShoppingCart* cart = new ShoppingCart();
    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();  
    cart->saveToDatabase();

    delete cart;
    return 0;
}