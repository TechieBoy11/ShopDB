// recipe.h
#include <string>
#include <vector>
 
struct Recipe {
    Recipe(const std::string &name, const std::vector <std::string> &ingredients): name(name), ingredients(ingredients) {};

    std::string name;
    std::vector <std::string> ingredients;
};