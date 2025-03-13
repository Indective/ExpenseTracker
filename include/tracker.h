#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
#include <string>
class Tracker {
    private:
        std::string fixed_dir = "Users";
    public:
        void Storetrans();
        void signuser(const std::string user_name, const std::string user_password);
        void createdir(const std::string &base_path);
        bool checkdir(const std::string &base_path);

};

#endif 
