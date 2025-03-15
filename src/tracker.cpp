#include "tracker.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>


namespace fs = std::filesystem;

void Tracker::Storetrans(const std::string &base_path, const std::string user_name)
{
    std::string full_path = base_path + "/" + fixed_dir + "/" + user_name;
    fs::current_path(full_path);
    std::string trans_name;
    std::string trans_category;
    int amount;
    std::string date;
    std::cout << std::endl << "Enter the name of the transaction: ";
    std::cin >> trans_name;
    std::cout << std::endl << "Enter the category of the transaction: ";
    std::cin >> trans_category;
    std::cout << std::endl << "Enter the amount of the transaction: ";
    std::cin >> amount;
    std::cin.ignore();
    std::cout << std::endl << "Enter the date of the transaction: ";
    std::cin >> date;
    if (trans_name == user_name)
    {
        std::cout << "Cannot set trasaction name as user name " << std::endl;
        
    }
    else
    {
        std::ofstream outfile(trans_name + ".txt");
        if(outfile.is_open())
        {
            outfile << trans_name << std::endl;
            outfile << trans_category << std::endl;
            outfile << amount << std::endl;
            outfile << date << std::endl;
            outfile.close();
            std::cout << "Transaction stored successfully" << std::endl;
        }   
    } 
}

bool Tracker::signuser(const std::string user_name , const std::string user_password, const std::string &base_path)
{
    std::string full_path = base_path + "/" + fixed_dir;
    fs::current_path(full_path);
    full_path = full_path + "/" + user_name;
    fs::create_directory(full_path);
    fs::current_path(full_path);
    std::ofstream outputFile (user_name + ".txt");
    if(outputFile.is_open())
    {
        outputFile << user_password << std::endl;
        outputFile.close();
        return true;
    }
    else
    {
        return false;
    }
}

void Tracker::createdir(const std::string &base_path)
{
    std::string full_path = base_path + "/" + fixed_dir;
    if(!checkdir(base_path))
    {
        fs::create_directory(full_path);
        fs::current_path(full_path);

    }
}

bool Tracker::checkdir(const std::string &base_path)
{
    std::string full_path = base_path + "/" + fixed_dir;
    try{
        for (auto const& i : fs::directory_iterator{base_path})
        {
            if(i.path().filename() == fixed_dir)
            {
                return true;
            }

        }
    }catch(const fs::filesystem_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    return false;
}

bool Tracker::login(const std::string user_name, const std::string user_password, const std::string base_path)
{
    std::string full_path = base_path + "/" + fixed_dir;
    try
    {
        for (auto &i : fs::directory_iterator{full_path})
        {
            
            if(i.path().filename() == user_name)
            {
                full_path = full_path + "/" + user_name;
                fs::current_path(full_path);
                std::ifstream infile;
                std::string password;
                infile.open(user_name + ".txt");
                if(infile.is_open())
                {
                    infile >> password; 
                    if(password == user_password)
                    {
                        system("cls");
                        std::cout << "Login successful" << std::endl;
                        return true;
                    }
                    else
                    {
                        std::cout << "Login failed" << std::endl;
                        return false;
                    }
                }
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return false;
    
}

void Tracker::viewtrans(const std::string user_name)
{
    std::cout << "Current transactions : " << std::endl;
    for (auto &i : fs::directory_iterator{fs::current_path().string()})
    {
        if (i.path().filename() != user_name + ".txt")
        {
            std::cout << i.path().filename() << std::endl;
        }
    }
}

void Tracker::transinfo(const std::string user_name, const std::string trans_name)
{
    for (auto &i : fs::directory_iterator{fs::current_path().string()})
    {
        if (i.path().filename() == trans_name)
        {
            std::string text;
            std::ifstream infile;
            infile.open(trans_name);
            if (infile.is_open())
            {
                while(std::getline(infile,text))
                {
                    std::cout << text << std::endl;
                }
                return;
            }
        }
    }
    std::cout << "Transaction not found" << std::endl;
}

