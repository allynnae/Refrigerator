CS 2401 – Fall 2023  
# Project 3 – Linked Lists  
Due: 11:59 PM Friday, October 13th  

Your refrigerator is a mess! You have no idea what you have in it or what you need to buy. You’ve gotten fed up and need to devise a way to keep yourself organized. You’ve decided to write a program that can keep track of two different lists; a list of what you have and a list of what you need to buy.  

You are not allowed to use any libraries or functions that we have not discussed in class.  

***

To get you started on this project, the Date class that we used in the last two projects has been altered so that it can now have a date object set to today, using the computer’s internal clock, and there is a function that allows us to know how many days old something is by sending a today object to another Date object (the return value is an integer).  

Using this updated Date class, a class called FoodItem is defined, which records the name of an ingredient (a string), it’s type (a string: dairy, meat, produce, etc.), a priority number (an integer), and the date when that item was added to a list (Date). The overloaded comparison operators for the FoodItem class are as follows: 

< and <= are based on the priority number, so if item1 < item2 it means that item1 has a lower priority than item2.  

\> and >= are based on the date the item was added, so if item1 > item2 it means that item1 has a date that comes after item2.  

***

You should begin the project by cloning your repository so you have a working copy of these files: 

* date_new.h 
* date_new.cc 
* fooditem.h 
* fooditem.cc 
* node.h (has the FoodItem as its data portion) 
* main.cc 
* stock_list.txt 

Your task is to create the header and implementation files for the Refrigerator class. This class will store a linked list of items already in the refrigerator AND a linked list of items that you need to buy (I have given you the node class you are to use). The “stock” list (what you already have) should be kept in order by what you have had the longest (the head should point to the item that was entered longest ago) and the “shopping” list (what you need to buy) should be kept in order by the priority number (highest priority at the head). This means that when a new item is added to either list, you will need to search through the list to put it in the right place. All comparison operators are overloaded for the FoodItem class, to facilitate this.  

The Refrigerator class will offer the application programmer the following options: 

* View the entire stock list and shopping list, in the order they are stored.  
* Add a new FoodItem to the stock list or to the shopping list (in the correct order).  
* Move an item from the shopping list to the stock list (assume you just bought the item today so you will need to change the date added to today).  
* Remove an item from either list. This will use the find function, and both find and remove will take a string which is the name of the item.  
* Output the number of items you have in each list.  
* See the item you have had in your refrigerator the longest (this item should be at the front of the stock list) and the item you most urgently need to buy (this item should be at the front of the shopping list).  
* See the average number of days you keep items in your refrigerator (use the days_old function provided).  
* List all stock and shopping list items from a particular category.  
* See all stock items that were added to your refrigerator on or before a specified date.  

The main that I have given you has a menu for all these options, and you should be able discern the names and parameters for the required functions from the calls that you see in the main.  

You will also need to have a load() and a save() that saves simply the information about the items (not the size of the list). I have provided a sample file for this purpose. The sample data file is in the format: item name, category, date added, priority number. There is a line with a single ‘*’ character to denote the separation between the stock and shopping list items.  

Since linked lists are built using dynamic memory, your class will be “holding” dynamic memory and that means that you will need to implement all of the Big 3 (hidden case ‘t’ in the menu will test your copy constructor).  

**Note:** since this container is responsible for **2** linked lists, you will need to make sure that you handle both lists correctly when initializing the object, making copies, and destroying.

***  

**Your final repository must include** the refrigerator.h and refrigerator.cc that you have created. Remember to comment and document your code appropriately.
