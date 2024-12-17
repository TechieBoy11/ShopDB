#ifndef PROGRAMHANDLER_H
#define PROGRAMHANDLER_H


#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "db.h"

class ProgramHandler {
    public:
        // Constructor for Database that accepts the name of the database (e.g., "students.csv") and load data using loadDB()
        ProgramHandler(std::string dbName);

        ~ProgramHandler();

        // handles reading in list from user and printing it
        void list();

        // handles reading in recipe from user and adding it to the database
        void addRecipe();

        // prints out the list of all recipes currently in the database
        void printRecipes();


    private:
    Database* db;
    bool error;

};

#endif