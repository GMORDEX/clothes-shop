#include <iostream>
#include <vector>
#include <algorithm>

class Item {
public:
    std::string name;
    double price;
    int quantity;

    Item(std::string itemName, double itemPrice, int itemQuantity)
        : name(itemName), price(itemPrice), quantity(itemQuantity) {}
};

class ShoppingCart {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& newItem) {
        items.push_back(newItem);
        std::cout << newItem.name << " added to the cart." << std::endl;
    }

    void removeItem(const std::string& itemName) {
        auto it = std::remove_if(items.begin(), items.end(),
            [&](const Item& item) { return item.name == itemName; });

        if (it != items.end()) {
            items.erase(it, items.end());
            std::cout << itemName << " removed from the cart." << std::endl;
        } else {
            std::cout << itemName << " not found in the cart." << std::endl;
        }
    }

    void displayCart() {
        if (items.empty()) {
            std::cout << "The shopping cart is empty." << std::endl;
        } else {
            std::cout << "Items in the shopping cart:" << std::endl;
            for (const auto& item : items) {
                std::cout << item.name << " - $" << item.price << " - Quantity: " << item.quantity << std::endl;
            }
        }
    }
};
