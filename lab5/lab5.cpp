#include <iostream>
#include <map>
using namespace std;

class Product {
private:
    string name;
    int stock;
public:
    Product(string n, int s) : name(n), stock(s) {}
    string getName() const { return name; }
    int getStock() const { return stock; }
    void setStock(int newStock) { stock = newStock; }
    void reduceStock(int quantity) { stock -= quantity; }
};

class VendingMachine {
private:
    map<string, Product> products;
public:
    VendingMachine();
    void displayProducts() const;
    void performTransaction(const string& choice);
    void addStock(const string& choice, int quantity);
    void run();
};

VendingMachine::VendingMachine() : products{
    {"P1", {"P1", 10}},
    {"P2", {"P2", 15}},
    {"P3", {"P3", 8}},
    {"P4", {"P4", 20}},
    {"P5", {"P5", 12}}
} {}

void VendingMachine::displayProducts() const {
    cout << "\nProduct List:\n";
    for (const auto& product : products) {
        cout << product.first << " Stock: " << product.second.getStock() << endl;
    }
}

void VendingMachine::performTransaction(const string& choice) {
    auto it = products.find(choice);
    if (it == products.end()) {
        cout << "Invalid selection. Please try again.\n";
        return;
    }
    int quantity;
    cout << "Enter quantity (available: " << it->second.getStock() << "): ";
    cin >> quantity;
    if (quantity <= 0 || quantity > it->second.getStock()) {
        cout << "Invalid quantity.\n";
        return;
    }
    it->second.reduceStock(quantity);
    cout << "Transaction completed. Remaining stock: " << it->second.getStock() << endl;
}

void VendingMachine::addStock(const string& choice, int quantity) {
    auto it = products.find(choice);
    if (it == products.end()) {
        cout << "Invalid product.\n";
        return;
    }
    it->second.setStock(it->second.getStock() + quantity);
    cout << "Stock updated for " << choice << ". New stock: " << it->second.getStock() << endl;
}

void VendingMachine::run() {
    cout << "Welcome to the Vending Machine!\n";
    while (true) {
        displayProducts();
        string choice;
        cout << "\nEnter product name to purchase: ";
        cin >> ws;
        getline(cin, choice);
        if (choice == "nic") {
            cout << "Service code accepted. Shutting off.\n";
            exit(0);
        }
        performTransaction(choice);
    }
}

int main() {
    VendingMachine vm;
    vm.run();
    return 0;
}
