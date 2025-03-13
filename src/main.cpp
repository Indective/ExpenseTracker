#include "tracker.h"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    Tracker t;
    std::string user_name;
    std::string user_password;
    std::string base_path = fs::current_path().parent_path().string();
    bool auth_sign;
    bool auth_login;

    t.createdir(base_path);
    std::cout << "What would you like to do? " << std::endl;
    std::cout << "1. Sign up" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::cout << "Enter your username: ";
            std::cin >> user_name;
            std::cout << "Enter your password: ";
            std::cin >> user_password;
            auth_sign = t.signuser(user_name, user_password, base_path);
            break;
        case 2:
            std::cout << "Enter your username: ";
            std::cin >> user_name;
            std::cout << "Enter your password: ";
            std::cin >> user_password;
            auth_login = t.login(user_name, user_password, base_path);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
    if (auth_sign || auth_login) 
    {
        while(true) {
            std::cout << "What would you like to do? " << std::endl;
            std::cout << "1. Store transaction" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch(choice) {
                case 1:
                    t.Storetrans(base_path, user_name);
                    break;
                default:
                    std::cout << "Invalid choice" << std::endl;
                    break;
            }
        }   
    }
    return 0;
}
