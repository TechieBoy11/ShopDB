// db.h
#ifndef DB_H
#define DB_H

#include <string>
#include <vector>
#include <fstream>
#include "student.h"
#include "rapidcsv.h"

class Database {
    public:
        // Constructor for Database that accepts the name of the database (e.g., "students.csv") and load data using loadDB()
        Database(std::string dbName);

        //Destructor that automatically saves the data using saveDB() when the Database object is destroyed.
        ~Database();

        // Inserts a new student into the students vector.
        void insertRecipe(const std::string &name, const std::vector <std::string> &ingredients);

        // Prints out the list of all students currently in the students vector.
        //Prints as comma separated list without any space between fields. Fields are separated by comma only. Students are separated by new line.
        void printRecipes() const;

        // prints a list of all ingredients
        void printList(std::vector<std::string> shoppingList) const;

    private:
        std::string dbName = "students.csv"; // stores the name of the CSV file

        std::vector<std::shared_ptr<Recipe>> recipes; // stores a list of students using std::shared_ptr.
        
        // loads student data from the CSV file
        // You can use rapidcsv, another csv library, or write code yourself to read CSV
        void loadDB();

        // saves student data to the CSV file
        // You can use rapidcsv, another csv library, or write code yourself to write CSV
        void saveDB(); 

};

#endif