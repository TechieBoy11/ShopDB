#define CATCH_CONFIG_MAIN  // This line tells Catch to provide a main() function

#include <cassert>    
#include <cstdlib>
#include "catch.hpp"
#include "db.h"
#include <iostream>
#include <filesystem> 

// This file tests the Database class. It pulls and saves data from CSV files located projectDirectory/test/testfiles.
// After each test the files in the delete folder need to be removed manually to ensure the tests run correctly.
/*
TEST_CASE("Test 1: Load from file basic") {
    Database db("../../test/testfiles/load.csv");
    std::vector<std::shared_ptr<Student>> students = db.getStudents();

    REQUIRE(students.size() == 1);
    REQUIRE(students[0]->name == "Alice");
    REQUIRE(students[0]->id == 1001);
    REQUIRE(students[0]->courseNumber == "ECE 3574");
    REQUIRE(students[0]->grade == "A");
}

TEST_CASE("Test 2: Load from file with extra columns") {
    REQUIRE_THROWS_AS(Database("../../test/testfiles/extraColumns.csv"), std::runtime_error);
}

TEST_CASE("Test 3: Load from file with blank student name") {
    Database db("../../test/testfiles/blankName.csv");
    std::vector<std::shared_ptr<Student>> students = db.getStudents();
    REQUIRE(students.size() == 0);
}

TEST_CASE("Test 4: Load from file that does not exist") {
    std::string dbName = "../../test/testfiles/delete/none.csv";
    Database db(dbName);

    // checks if the file exists  
    REQUIRE(std::filesystem::exists(dbName));  
}

TEST_CASE("Test 5: Load from file with incompatible variable type") {
    REQUIRE_THROWS_AS(Database("../../test/testfiles/incompatible.csv"), std::runtime_error);
}

TEST_CASE("Test 6: Insert test student") {
    Database db("../../test/testfiles/delete/insert.csv");
    db.insertStudent("Bob", 1002, "ECE 3574", "B-");
    std::vector<std::shared_ptr<Student>> students = db.getStudents();

    REQUIRE(students.size() == 1);
    REQUIRE(students[0]->name == "Bob");
    REQUIRE(students[0]->id == 1002);
    REQUIRE(students[0]->courseNumber == "ECE 3574");
    REQUIRE(students[0]->grade == "B-");
}

TEST_CASE("Test 7: Save test with a student") {
    // checking if test 6 destructor saves the data to the file
    Database db("../../test/testfiles/delete/insert.csv");

    std::vector<std::shared_ptr<Student>> students = db.getStudents();
    REQUIRE(students.size() == 1);
}

TEST_CASE("Test 8: Disconnect") {
    Database db("../../test/testfiles/delete/disconnect.csv");
    db.disconnect();
    // checks if the database is disconnected, when disconnected the database should not be able to insert a student
    REQUIRE_THROWS_AS((db.insertStudent("Alice", 1001, "ECE 3574", "A")), std::runtime_error);
}

TEST_CASE("Test 9: Connect") {
    Database db("../../test/testfiles/delete/connect.csv");
    db.disconnect();
    db.connect();
    db.insertStudent("Alice", 1001, "ECE 3574", "A");
    std::vector<std::shared_ptr<Student>> students = db.getStudents();
    // checks if the database is connected, when the database is conected inserting a student works as normal
    REQUIRE(students[0]->name == "Alice");
}


*/