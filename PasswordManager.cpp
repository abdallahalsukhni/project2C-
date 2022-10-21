#include <iostream>
// #include <string>
#include "PasswordManager.h"
using namespace std;
// using std::string;

class PasswordManager {

	public:
		string username;
		string password;
		
		// sets password to a new encrypted password
		void PasswordManager::setEncryptedPassword(string newEncryptedPassword) {
			encryptedPassword = newEncryptedPassword;
		}

		// sets username to a new username
		void PasswordManager::setUsername(string newUsername) {
			username = newUsername;
		}

		bool PasswordManager::setNewPassword(string password) {
			if(!meetsCriteria(password)) {
				return false;
			}
			encryptedPassword = encrypt(password);
			return true;
		}

		bool PasswordManager::authenticate(string password) {
			string encrypted = encrypt(password);
			return encrypted == encryptedPassword;
		}

	private:

		string PasswordManager::encrypt(string password) {
			int amountToLoop = password.length();
			string newString = "";
			for(int spot = 0; spot < amountToLoop; spot++) {
				char currentChar = password[spot];
				int currentCharInt = static_cast<int>(currentChar);
				int newCharInt = ((currentCharInt - 33) + 25) % 94 + 33;
				char newChar = static_cast<char>(newCharInt);
				newString += newChar;
			}
			return newString;
		}

		bool PasswordManager::meetsCriteria(string password) {
			if(password.length() < 8) {
				return false;
			}
			bool upperCase = false;
			bool lowerCase = false;
			bool digit = false;
			for(int spot = 0; spot < password.length(); spot++) {
				char currChar = password[spot];
				if(isupper(currChar)){
					upperCase = true;
				}
				if(islower(currChar)) {
					lowerCase = true;
				}
				if(isdigit(currChar)) {
					digit = true;
				}
			}
			return upperCase && lowerCase && digit;
		}

}
