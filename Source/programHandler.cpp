#include "programHandler.h"

ProgramHandler::ProgramHandler(std::string dbName) {
    db = new Database(dbName);
}

ProgramHandler::~ProgramHandler() {
    delete db;
}

void ProgramHandler::creatList() {
    shoppingList.clear();;
    std::string name;
    while (true) {
        std::cout << "Enter the name of the recipe you want to add to the shopping list: ";
        std::cin >> name;
        if (name == "done")
            break;
        shoppingList.push_back(name);
    }
    ingredients = db->printList(shoppingList);

    // print out a list of ingredients
    std::cout << "Shopping List:" << std::endl;
    for (size_t i = 0; i < ingredients.size(); i++) 
        std::cout << ingredients[i] << std::endl;
}

// TODO: add remove or edit functionality 
void ProgramHandler::addRecipe() {
    std::string name;
    std::vector<std::string> ingredients;
    std::string ingredient;

    std::cout << "Enter the name of the recipe: ";
    std::cin >> name;

    // TODO: check if name is in db already

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

void ProgramHandler::sendMessage() {
    // Runs the python script located in the home directory.
    std::cout << "preparing send" << std::endl;
    //std::vector<std::string> shoppingList = db->getShoppingList();

    // Asks user for phone number TODO: confirm phone number format
    std::string phoneNumber{"7138553047"};
    //std::cout << "What number would you like to send list to: "<< std::endl;
    //std::cin >> phoneNumber;

    // Build command line: python "scriptPath" phoneNumber
    std::string cmdLine = "python \"" + scriptPath + "\" " + phoneNumber;

    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    char cmdLineCStr[512];
    errno_t err = strncpy_s(cmdLineCStr, sizeof(cmdLineCStr), cmdLine.c_str(), _TRUNCATE);
    if (err != 0) {
        std::cerr << "Failed to copy command line string safely\n";
        return;
    }

    if (!CreateProcess(
            nullptr,
            cmdLineCStr,
            nullptr,
            nullptr,
            FALSE,
            CREATE_NO_WINDOW,
            nullptr,
            nullptr,
            &si,
            &pi))
    {
        std::cerr << "Failed to launch python script. Error: " << GetLastError() << std::endl;
        return;
    }

    // Close handles to avoid waiting for the child process
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    std::cout << "Text message script launched in background." << std::endl;


    
}