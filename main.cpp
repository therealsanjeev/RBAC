#include <string>
#include "User.h"
#include "Resource.h"
#include "Role.h"
#include <list>
#include <iostream>

using namespace std;

list<User> users;

User* addUser(string name) {
    User user = *new User();
    user.name = name;
    users.push_back(user);
    return &user;
}

User *addAccess(User &user, string access) {

    if (access == "READ") {
        user.READ = true;
    }
    if (access == "WRITE") {
        user.WRITE = true;
    }
    return &user;
}

void addResource(User user, Resource resource) {
    user.resource = resource;
}

void addAccessOnResource(User user) {
    user.resource.READ = true;

}

void addActionOnResource(User user) {
    user.resource.WRITE = true;
}

void addRole(User user, Role role) {
    user.role = role;
}

void addAccessOnResourceToRole(User user) {
    user.ADMIN = true;
    user.resource.READ = true;

}

bool addRoleToUser(User user, Role role) {
    user.role = role;
}

bool checkAccess(User user) {

    if (user.resource.READ) {
        return true;
    } else if (user.resource.WRITE) {
        return true;
    }
    return false;
}

void printUsers() {
    for (auto it: users) {
        cout << it.name << endl;
    }
}

User *findUser(string name) {
    User user = *new User();
    for (auto it: users) {
        if (it.name == name) {
            user = it;

        }
    }
    return &user;
}

int main() {

    users = *new list<User>();

    cout << addUser("Ankit")->name << endl;
    cout << addUser("xyz")->name << endl;

    User *user = findUser("Ankit");

    user = addAccess(*user, "READ");
    cout << user->READ << endl;

    printUsers();

}
