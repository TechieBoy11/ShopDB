// student.h
#include <string>
#include <vector>

//Student struct that holds the name, id, course number, and grade of a student
struct Student {
    Student(const std::string &name, const int id, const std::string &courseNumber, const std::string &grade);

    std::string name;
    int id;
    std::string courseNumber;
    std::string grade;
};
 
struct Recipe {
    Recipe(const std::string &name, const std::vector <std::string> &ingredients): name(name), ingredients(ingredients) {};

    std::string name;
    std::vector <std::string> ingredients;
};