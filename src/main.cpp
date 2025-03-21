// TODO :
// fix deposit(), avgspending(),and getTransCateg()
// extend balance logic
// clean up code, move menu screens into functions
// refactor everything
// STOP USING system("cls") 

#include "tracker.h"
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    Tracker t;
    Stats s;
    std::string user_name;
    std::string user_password;
    int balance;
    std::string base_path = fs::current_path().parent_path().string();
    bool auth_sign;
    bool auth_login;

    t.createdir(base_path);
    std::cout << "What would you like to do? " << std::endl;
    std::cout << "1. Sign up" << std::endl;
    std::cout << "2. Login" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::cout << "Enter your username: ";
            std::cin >> user_name;
            std::cout << "Enter your password: ";
            std::cin >> user_password;
            std::cout << "Enter your current bank balance : ";
            std::cin >> balance;
            auth_sign = t.signuser(user_name, user_password, base_path, balance);
            break;
        case 2:
            std::cout << "Enter your username: ";
            std::cin >> user_name;
            std::cout << "Enter your password: ";
            std::cin >> user_password;
            auth_login = t.login(user_name, user_password, base_path);
            break;
        case 3:
            exit(0);
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
    }
    if (auth_sign || auth_login) 
    {
        std::string trans_name;
        while(true) 
        {
            std::cout << "What would you like to do? " << std::endl;
            std::cout << "1. Store transaction" << std::endl;
            std::cout << "2. View stored transactions" << std::endl;
            std::cout << "3. View transaction info" << std::endl;
            std::cout << "4. View general account info + stats" << std::endl;
            std::cout << "5. Deposit" << std::endl;
            std::cout << "6. Exit." << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            switch(choice) 
            {
                case 1:
                    system("cls");
                    t.Storetrans(base_path, user_name);
                    break;
                case 2:
                    system("cls");
                    t.viewtrans(user_name);
                    break;
                case 3:
                    system("cls");
                    std::cout << "Enter transaction name : ";
                    std::cin >> trans_name;
                    trans_name = trans_name + ".txt";
                    t.transinfo(user_name, trans_name);
                    break;
                case 4:
                    s.generalscreen(user_name, user_password, base_path, balance);
                    break;
                case 5 :
                    int amount;
                    std::cout << "Enter amount to deposit : ";
                    std::cin >> amount;
                    t.deposit(user_name, amount);
            }
        }   
    }
    return 0;
}
