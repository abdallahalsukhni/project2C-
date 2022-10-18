// #include <iostream>
// #include <string>
#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H
// PasswordManager declaration class
using std::string;
class PasswordManager {
    private:
        std::string username;
        std::string encryptedPassword; 
        std::string encrypt(string);   
        bool meetsCriteria(string);
    public:
        void setUsername(string);
        void setEncryptedPassword(string);
        std::string getUsername() const {return username;}
        std::string getEncryptedPassword() const {return encryptedPassword;}
        bool setNewPassword(string);
        bool authenticate(string);
};
#endif