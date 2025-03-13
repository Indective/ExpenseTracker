#include "tracker.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>


namespace fs = std::filesystem;

void Tracker::Storetrans()
{

}

void Tracker::signuser(const std::string user_name , const std::string user_password)
{
    fs::create_directory(user_name);
    std::string text;
    std::ofstream outputFile(user_name);
    if(outputFile.is_open())
    {
        outputFile << user_password << std::endl;
        outputFile.close();
    }
    
}

void Tracker::createdir(const std::string &base_path)
{
    std::string full_path = base_path + "/" + fixed_dir;
    if(!checkdir(base_path))
    {
        fs::current_path(full_path);
        fs::create_directory(full_path);

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

