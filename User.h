//
// Created by Sanjeev Gupta on 09/01/23.
//

#ifndef BLOCKCHAIN_USER_H
#define BLOCKCHAIN_USER_H


#include "Resource.h"
#include "Role.h"
#include <string>


class User {


public:
    bool READ =false;
    bool WRITE= false;
    Resource resource;
    bool ADMIN= false;
    Role role;

    std::string name;

};


#endif //BLOCKCHAIN_USER_H
