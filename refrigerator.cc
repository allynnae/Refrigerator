/**
 *   @file: refrigerator.cc
 * @author: Allison McKee
 *   @date: 10-16-2023
 *  @brief: This is the implementation file for the Refrigerator class.
 */
#include <iostream>
#include <string>

#include "refrigerator.h"

using namespace std;

// Constructor
Refrigerator::Refrigerator(){
    stock_head = nullptr;
    shopping_head = nullptr;
}

// Big 3
// Destructor
Refrigerator::~Refrigerator(){
    // Delete all nodes in the stock list
    while (stock_head != nullptr){
        node *tmp = stock_head;
        stock_head = stock_head -> next();
        delete tmp;
    }

    // Delete all nodes in the shopping list
    while (shopping_head != nullptr){
        node *tmp = shopping_head;
        shopping_head = shopping_head -> next();
        delete tmp;
    }
}

// Copy Constructor
Refrigerator::Refrigerator(const Refrigerator &other){
    if (other.stock_head == nullptr){
        stock_head = nullptr;
    }
    else if (other.shopping_head == nullptr){
        shopping_head = nullptr;
    }
    else
    {
        // Copy the stock list
        node *cursor = other.stock_head;
        node *prev = nullptr;

        // While the other stock node isn't empty
        while (cursor != nullptr){
            // Create new node
            node *new_node = new node(cursor -> data());
            if (!stock_head){
                stock_head = new_node;
            }
            else{
                prev -> set_next(new_node);
            }
            prev = new_node;
            cursor = cursor -> next();
        }

        // Copy the shopping list
        cursor = other.shopping_head;
        prev = nullptr;

        // While the other shopping node isn't empty
        while (cursor != nullptr){
            // Create new node
            node *new_node = new node(cursor -> data());
            if (!shopping_head){
                shopping_head = new_node;
            }
            else{
                prev -> set_next(new_node);
            }
            prev = new_node;
            cursor = cursor -> next();
        }
    }
}

// Operator Assignment
Refrigerator &Refrigerator::operator = (const Refrigerator &other){
    // Check for self assignment
    if (this == &other){
        return *this;
    }

    // Delete the old list - deconstructor code
    // Delete all nodes in the stock list
    while (stock_head != nullptr){
        node *tmp = stock_head;
        stock_head = stock_head -> next();
        delete tmp;
    }

    // Delete all nodes in the shopping list
    while (shopping_head != nullptr){
        node *tmp = shopping_head;
        shopping_head = shopping_head -> next();
        delete tmp;
    }

    // Make a copy - copy constructor code
    // Copy the stock list
    node *cursor = other.stock_head;
    node *prev = nullptr;

    // While the other stock node isn't empty
    while (cursor != nullptr){
        // Create new node
        node *new_node = new node(cursor -> data());
        if (!stock_head){
            stock_head = new_node;
        }
        else{
            prev -> set_next(new_node);
        }
        prev = new_node;
        cursor = cursor -> next();
    }

    // Copy the shopping list
    cursor = other.shopping_head;
    prev = nullptr;

    // While the other shopping node isn't empty
    while (cursor != nullptr){
        // Create new node
        node *new_node = new node(cursor -> data());
        if (!shopping_head){
            shopping_head = new_node;
        }
        else{
            prev -> set_next(new_node);
        }
        prev = new_node;
        cursor = cursor -> next();
    }
    return *this;
}

// Display
void Refrigerator::display(ostream &outs) const{
    // Display the stock list
    cout << "Stock List:" << endl;
    node* cursor = stock_head;
    while (cursor != nullptr) {
        cout << cursor -> data() << endl;
        cursor = cursor -> next();
    } 

    // Display the shopping list
    cout << "Shopping List:" << endl;
    cursor = shopping_head;
    while (cursor != nullptr) {
        cout << cursor -> data() << endl;
        cursor = cursor -> next();
    }
}

// Add
void Refrigerator::add(string list_type, const FoodItem &item){
    node* cursor = nullptr;

    // Set the cursor to the correct list
    if (list_type == "shopping"){
        cursor = shopping_head;
    } else if (list_type == "stock"){
        cursor = stock_head;
    } 
    else{
        cout << "Invalid list type." << endl;
        return;
    }

    // Create a new node
    node* new_node = new node;
    new_node -> set_data(item);

    if (cursor == nullptr){
        // If the list is empty, set the new node as the head
        if (list_type == "shopping"){
            shopping_head = new_node;
        } else if (list_type == "stock"){
            stock_head = new_node;
        }
    } 
    else{
        // If the list is not empty, add the new node
        while (cursor -> next() != nullptr){
            cursor = cursor -> next();
        }
        cursor -> set_next(new_node);
    }
}

// Find
FoodItem Refrigerator::find(const string& list_type, const string& item_name)const{
    node* cursor = nullptr;

    // Set the cursor to the correct list
    if (list_type == "shopping"){
        cursor = shopping_head;
    } else if (list_type == "stock"){
        cursor = stock_head;
    } 
    else{
        cout << "Invalid list name." << endl;
        // Return a default FoodItem 
        return FoodItem();  
    }

    while (cursor != nullptr){
        if (cursor -> data().get_name() == item_name){
            // If item is found, return it
            return cursor -> data();
        }
        cursor = cursor -> next();
    }
    // If item is not found, return a default FoodItem
    return FoodItem();
}

// Move
void Refrigerator::move_to_stock(const string& item_name){
    node* cursor = shopping_head;
    node* prev = nullptr;
    
    while (cursor != nullptr){
        // If the item is in the shopping list
        if (cursor -> data().get_name() == item_name){
            // Remove from the shopping list
            if (prev != nullptr){
                prev -> set_next(cursor -> next());
            } 
            else{
                shopping_head = cursor -> next();
            }
            // Add to the stock list
            add("stock", cursor -> data());
            // Delete cursor
            delete cursor;
            return;
        }
        prev = cursor;
        cursor = cursor -> next();
    }

    cout << "Item not found in the shopping list." << endl;

}

void Refrigerator::remove(const string& list_type, const string& item_name){
    node* cursor = nullptr;
    node* prev = nullptr;

    // Set the cursor to the correct list
    if (list_type == "shopping"){
        cursor = shopping_head;
    } else if (list_type == "stock"){
        cursor = stock_head;
    } 
    else{
        cout << "Invalid list type." << endl;
        return;
    }

    while (cursor != nullptr){
        // If the item is in a list
        if (cursor -> data().get_name() == item_name){
            // Remove from the list
            if (prev != nullptr){
                prev -> set_next(cursor -> next());
            } 
            else{
                // If the item to remove is the head
                if (list_type == "shopping"){
                    shopping_head = cursor -> next();
                } else if (list_type == "stock"){
                    stock_head = cursor -> next();
                }
            }
            // Delete cursor
            delete cursor;
            cout << "Item '" << item_name << "' has been removed from the " << list_type << " list." << endl;
            return;
        }
        prev = cursor;
        cursor = cursor -> next();
    }
    cout << "Item not found in the " << list_type << " list." << endl;
}

// Count items
void Refrigerator::item_counts()const{
    int stock_count = 0;
    int shopping_count = 0;

    // Count items in the stock list
    node* cursor = stock_head;
    while (cursor != nullptr) {
        stock_count++;
        cursor = cursor -> next();
    }

    // Count items in the shopping list
    cursor = shopping_head;
    while (cursor != nullptr) {
        shopping_count++;
        cursor = cursor -> next();
    }
    cout << "Items in Stock List: " << stock_count << endl;
    cout << "Items in Shopping List: " << shopping_count << endl;
}

// Oldest and Most Urgent
void Refrigerator::oldest_and_mostUrgent()const{
    // Oldest item in the stock list
    node* cursor = stock_head;
    FoodItem oldest_item;
    FoodItem most_urgent;
    Date oldest_date;
    int highest_priority = 0;

    // Find the oldest item in the stock list
    while (cursor != nullptr){
        if (cursor -> data().get_added() < oldest_date || oldest_date == Date()){
            oldest_date = cursor -> data().get_added();
            oldest_item = cursor -> data();
        }
        cursor = cursor -> next();
    }

    // Most urgent item in the shopping list
    cursor = shopping_head;

    // Find the item with the highest priority in the shopping list
    while (cursor != nullptr){
        // While the item's priority is higher than 0
        if (cursor -> data().get_priority() > highest_priority){
            highest_priority = cursor -> data().get_priority();
            most_urgent = cursor -> data();
        }
        cursor = cursor -> next();
    }

    // Display the results
    cout << "Oldest item in the stock list:\n" << oldest_item << endl;
    cout << "Most urgent item in the shopping list:\n" << most_urgent << endl;
}

// Average 
double Refrigerator::average_days()const{
    // Check if stock is empty
    if (stock_head == nullptr){
        return 0.0; 
    }
    node* cursor = stock_head;
    double average;
    double total_days = 0.0;
    int count = 0;

    while (cursor != nullptr){
        Date current_date;
        current_date.make_today();

        // Calculate the number of days the item has been in the refrigerator
        int days = cursor -> data().get_added().days_old(current_date);

        total_days += days;
        count++;
        cursor = cursor -> next();
        // Calculate the average 
        average = total_days / count;
    }
    // Return the average
    return average;
}

// List by category
void Refrigerator::list_by_category(const string& category){
    // List stock items for the specific category
    cout << "Stock items in the " << category << " category:" << endl;
    node *cursor = stock_head;
    while (cursor != nullptr){
        if (cursor -> data().get_category() == category){
            cout << cursor -> data() << endl;
        }
        cursor = cursor -> next();
    }

    // List shopping items for the specific category
    cout << "\nShopping list items in the " << category << " category:" << endl;
    cursor = shopping_head;
    while (cursor != nullptr)
    {
        if (cursor -> data().get_category() == category)
        {
            cout << cursor -> data() << endl;
        }
        cursor = cursor -> next();
    }
}

// Find All (See all stock items that were added to the refrigerator on or before a specified date)
void Refrigerator::find_all(const Date& had_since)const{
    node* cursor = stock_head;
    Date added_date;
    
    while (cursor != nullptr){
        added_date = cursor -> data().get_added();
        // If the added date is less than or equal to the had since date
        if (added_date <= had_since){
            cout << cursor -> data() << endl;
        }
        cursor = cursor -> next();
    }
}

// Load -> this is not working correctly, but when you run it without a pre-existing file the program works correctly
void Refrigerator::load(istream &ins){
    node* cursor = stock_head;
    while (cursor != nullptr){
        cursor -> data().input(ins);
        cursor = cursor -> next();
    }
    cursor = shopping_head;
    while (cursor != nullptr){
        cursor -> data().input(ins);
        cursor = cursor -> next();
    }
}

// Save
void Refrigerator::save(ostream &outs){
    // Save stock list
    node* cursor = stock_head;
    while (cursor != nullptr){
        cursor -> data().output(outs);
        cursor = cursor -> next();
    }

    // Separate lists like how it is in the original file
    outs << "*" << endl;

    // Save shopping list
    cursor = shopping_head;
    while (cursor != nullptr){
        cursor -> data().output(outs);
        cursor = cursor -> next();
    }
}