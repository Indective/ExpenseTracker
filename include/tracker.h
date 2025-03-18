#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
#include <string>
#include <vector>
class Tracker {
    private:
        std::string fixed_dir = "Users";
    public:
        void Storetrans(const std::string &base_paths, const std::string user_name);
        bool signuser(const std::string user_name, const std::string user_password, const std::string &base_path, const int bank_balance);
        void createdir(const std::string &base_path);
        bool checkdir(const std::string &base_path);
        bool login (const std::string user_name, const std::string user_password,const std::string base_path);
        void viewtrans(const std::string user_name);
        void transinfo(const std::string user_name, const std::string trans_name);
        void deposit(const std::string user_name, const int amount);


};

class Stats
{
    public:
        void avgspending(const std::string user_name);
        void getTransCateg(const std::string user_name);
        void generalscreen(const std::string user_name, const std::string user_password, const std::string base_path, const int balance);
};

#endif 
