#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
#include <string>
class Tracker {
    private:
        std::string fixed_dir = "Users";
    public:
        void Storetrans(const std::string &base_paths, const std::string user_name);
        bool signuser(const std::string user_name, const std::string user_password, const std::string &base_path);
        void createdir(const std::string &base_path);
        bool checkdir(const std::string &base_path);
        bool login (const std::string user_name, const std::string user_password,const std::string base_path);
        void viewtrans(const std::string user_name);
        void transinfo(const std::string user_name, const std::string trans_name);

};

#endif 
