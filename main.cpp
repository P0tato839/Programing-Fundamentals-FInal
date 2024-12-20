#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Define a structure for an item in the inventory
struct Item {
    string name;   // name
    int quantity;  // Quantity of item
    float price;   // cost per item
};

int main() {
    Item inventory[10];  //  holds up to 10 items
    int itemCount = 0;    // Keep track of items
    int choice;

    // Main loop for the menu
    do {
        // Display the menu
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item Quantity\n";
        cout << "3. Display Inventory\n";
        cout << "4. Display Total Value of Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {  // Add Item
            if (itemCount < 10) {  // Check if there is space for more items
                cout << "Enter item name: ";
                cin.ignore();  // Clear the buffer
                getline(cin, inventory[itemCount].name);
                cout << "Enter item quantity: ";
                cin >> inventory[itemCount].quantity;
                cout << "Enter item price: ";
                cin >> inventory[itemCount].price;
                itemCount++;  // Increase items quantity
                cout << "Item added successfully!\n";
            } else {
                cout << "Inventory is full, can't add more items.\n";
            }
        }
        else if (choice == 2) {  // Update Item Quantity
            string itemName;
            cout << "Enter the name of the item to update: ";
            cin.ignore();  // Clear the buffer
            getline(cin, itemName);

            bool found = false;  // check if item was found
            for (int i = 0; i < itemCount; i++) {
                if (inventory[i].name == itemName) {
                    cout << "Enter new quantity for " << itemName << ": ";
                    cin >> inventory[i].quantity;
                    found = true;
                    cout << "Quantity updated successfully!\n";
                    break;
                }
            }
            if (!found) {
                cout << "Item not found.\n";
            }
        }
        else if (choice == 3) {  // Display Inventory
            if (itemCount == 0) {
                cout << "No items in the inventory.\n";
            } else {
                cout << "\nInventory List:\n";
                cout << left << setw(20) << "Item Name"
                     << setw(10) << "Quantity"
                     << setw(10) << "Price"
                     << setw(10) << "Total Value" << endl;
                for (int i = 0; i < itemCount; i++) {
                    float totalValue = inventory[i].quantity * inventory[i].price;
                    cout << left << setw(20) << inventory[i].name
                         << setw(10) << inventory[i].quantity
                         << setw(10) << fixed << setprecision(2) << inventory[i].price
                         << setw(10) << fixed << setprecision(2) << totalValue << endl;
                }
            }
        }
        else if (choice == 4) {  // Display Total Value
            float totalInventoryValue = 0.0;
            for (int i = 0; i < itemCount; i++) {
                totalInventoryValue += inventory[i].quantity * inventory[i].price;
            }
            cout << "Total value of the inventory: $" << fixed << setprecision(2) << totalInventoryValue << endl;
        }
        else if (choice == 5) {  // end
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 5);  // Repeat till ended

    return 0;
}
