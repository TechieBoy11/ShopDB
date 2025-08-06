#include "programHandler.h"

#include <iostream>

int main() {
    // Handles db save and read in
    std::cout << "Hello, welcome to the recipe database!" << std::endl;
    std::cout << "Would you like to use the defult file 'recipes.csv'? (y/n): ";
    std::string response;
    std::cin >> response;

    std::string fileName = "../../saveFiles/recipes.csv";
    if (response == "n") {
        std::cout << "Enter the name of the file you would like to use: ";
        std::cin >> response;
        fileName = "../../saveFiles/" + response;
    }

    // initializes program handler (this will initilize the database)
    ProgramHandler handler(fileName);

    // main program loop
    while (true) {
        std::cout << "\n////////////////////////////////////////////////////////////////////" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "0. send message" << std::endl;
        std::cout << "1. Add a recipe" << std::endl;
        std::cout << "2. Add a recipe to the shopping list" << std::endl;
        std::cout << "3. Print all recipes" << std::endl;
        std::cout << "4. Exit" << std::endl;
        int choice;
        std::cin >> response;
        std::cout << "////////////////////////////////////////////////////////////////////\n" << std::endl;

        try {
            choice = std::stoi(response);
        } catch (...) {
            std::cout << "Invalid choice: exited" << std::endl;
            return 0;
        }
        switch (choice) {
            case 0:
                handler.creatList();
                handler.sendMessage(); // Example phone number
                break;
            case 1:
                handler.addRecipe();
                break;
            case 2:
                handler.creatList();
                break;
            case 3:
                handler.printRecipes();
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice: exited" << std::endl;
                return 0;
        }
    }


    return 0;
}

