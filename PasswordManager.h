#include <iostream>
#include <string>
#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H
// PasswordManager declaration class
using namespace std;
class PasswordManager {
    private:
        string username;
        string encryptedPassword; 
        string encrypt(string);   
        bool meetsCriteria(string);
    public:
        void setUsername(string);
        void setEncryptedPassword(string);
        string getUsername() const;
        string getEncryptedPassword() const;
        bool setNewPassword(string);
        bool authenticate(string);
}
#endif