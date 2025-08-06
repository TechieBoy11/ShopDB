# include "db.h"

Database::Database(std::string dbName) {
    this->dbName = dbName;
    loadDB();
}

Database::~Database() {
    saveDB();
}


void Database::insertRecipe(const std::string &name, const std::vector <std::string> &ingredients) {
    // check if the student id already exists to prevent duplication  
    for (const auto& recipe : recipes) {
        if (recipe->name == name) {
            std::cout << "Recipe already exists" << std::endl;
            return;
        }
    }

    recipes.push_back(std::make_shared<Recipe>(name, ingredients));
}

void Database::printRecipes() const{
    for (const auto& recipe : recipes) {
        std::cout << recipe->name << ": ";
        for (size_t i = 0; i < recipe->ingredients.size(); i++) {
            std::cout << recipe->ingredients[i];
            if (i != recipe->ingredients.size() - 1)
                std::cout << ",";
        }
        std::cout << std::endl;
    }
}

void Database::printList(std::vector<std::string> shoppingList) const {
    std::vector<std::string> ingredients;
    // collect all ingredients from the recipes
    for (const auto& recipeName : shoppingList) {
        for (const auto& recipeLookup : recipes) {
            if (recipeName == recipeLookup->name) {
                for (const auto& ingredient : recipeLookup->ingredients) {
                    ingredients.push_back(ingredient);
                }
            }
            else {
                std::cout << "Recipe not found: " << recipeName << std::endl;
            }
        }
    }

    // remove duplicated ingredients
    for (auto ingredient : ingredients) {
        for (auto ingredientLookup : ingredients) {
            if (ingredient == ingredientLookup) {
                ingredients.erase(std::remove(ingredients.begin(), ingredients.end(), ingredientLookup), ingredients.end());
                ingredients.push_back(ingredientLookup);
            }
        }
    }

    // print out a list of ingredients
    std::cout << "Shopping List:" << std::endl;
    for (size_t i = 0; i < ingredients.size(); i++) 
        std::cout << ingredients[i] << std::endl;
    
}
        
void Database::loadDB() {
    bool error = false;

    try {
        rapidcsv::Document doc(dbName, rapidcsv::LabelParams(-1, -1));
        // Throws an error if the file is not formatted correctly (either too many columns or too little rows)
        if (doc.GetColumnCount() < 2) 
            std::cout << "Error: No recipes found" << std::endl;
                
        for (size_t rowIndex = 0; rowIndex < doc.GetRowCount(); rowIndex++) {
            // Rows with blank student name will be skipped
            if (doc.GetCell<std::string>(0, rowIndex) != ""){
                std::string name = doc.GetCell<std::string>(0, rowIndex);
                std::vector<std::string> ingredients;
                for (size_t colIndex = 1; colIndex < doc.GetColumnCount(); colIndex++) {
                    if (doc.GetCell<std::string>(colIndex, rowIndex) != "") 
                        ingredients.push_back(doc.GetCell<std::string>(colIndex, rowIndex));
                }
                recipes.push_back(std::make_shared<Recipe>(name, ingredients));
            }
        }
    } catch (...) {
        // If the file does not open, a new file will be created
        std::cout << "File not found, new file being created" << std::endl;
        std::ofstream file(dbName);
        if (!file.is_open())
            throw std::runtime_error("File could not be created");
        file.close();
    }
    
}

void Database::saveDB() {
    rapidcsv::Document doc(dbName, rapidcsv::LabelParams(-1, -1));
    size_t rowIndex = 0;

    // loop through the students vector and prepairs to save the data
    for (const auto& recipe : recipes) {
        doc.SetCell<std::string>(0, rowIndex, recipe->name);
        for (size_t colIndex = 1; colIndex < recipe->ingredients.size() + 1; colIndex++) {
            if (recipe->ingredients[colIndex - 1] != "") 
                doc.SetCell<std::string>(colIndex, rowIndex, recipe->ingredients[colIndex - 1]);
            else
                break;
        }
        rowIndex++;
    }

    // save the data to the CSV file
    doc.Save(dbName); 
}
