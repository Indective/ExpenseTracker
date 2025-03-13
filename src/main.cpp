#include "tracker.h"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    Tracker t;
    std::string user_name;
    std::string user_password;
    std::string base_path = fs::current_path().string();
    std::string i = "hello";
    std::stirng a = "";

    
    std::cout << "Enter your user name : ";
    std::getline(std::cin, user_name);

    std::cout << "Enter your user password : ";
    std::getline(std::cin, user_password);

    t.createdir(base_path);
    t.signuser(user_name, user_password);
    return 0;
}
