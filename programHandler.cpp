#include "programHandler.h"

ProgramHandler::ProgramHandler(std::string dbName) {
    db = new Database(dbName);
}

ProgramHandler::~ProgramHandler() {
    delete db;
}

void ProgramHandler::list() {
    std::vector<std::string> recipeList;
    std::string name;
    while (true) {
        std::cout << "Enter the name of the recipe you want to add to the shopping list: ";
        std::cin >> name;
        if (name == "done")
            break;
        recipeList.push_back(name);
    }
    db->printList(recipeList);
}

void ProgramHandler::addRecipe() {
    std::string name;
    std::vector<std::string> ingredients;
    std::string ingredient;

    std::cout << "Enter the name of the recipe: ";
    std::cin >> name;

    while (true) {
        std::cout << "Enter the ingredient: ";
        std::cin >> ingredient;
        if (ingredient == "done")
            break;
        ingredients.push_back(ingredient);
    }
    
    db->insertRecipe(name, ingredients);
}

void ProgramHandler::printRecipes() {
    db->printRecipes();
}