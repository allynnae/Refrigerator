/**
 *   @file: refrigerator.h
 * @author: Allison McKee
 *   @date: 10-16-2023
 *  @brief: This is the header file for the Refrigerator class.
 */
#include <iostream>
#include <string>
#include "node.h"
#include "fooditem.h"

#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

using namespace std;

// Refrigerator class
class Refrigerator{
    public:
        // Constructor
        Refrigerator();

        // Big 3
        ~Refrigerator();
        Refrigerator(const Refrigerator& other);
        Refrigerator& operator = (const Refrigerator& other);

        void display(ostream& outs)const;
        void add(string list_type, const FoodItem &item);
        FoodItem find(const string& list_name, const string& item_name)const;
        void move_to_stock(const string &item_name);
        void remove(const string& list_type, const string& item_name);
        void item_counts()const;
        void oldest_and_mostUrgent()const;
        double average_days()const;
        void list_by_category(const string& category);
        void find_all(const Date& had_since)const;

        void load(istream &ins);
        void save (ostream &outs);

    private:
        node* stock_head;
        node* shopping_head;
};

#endif