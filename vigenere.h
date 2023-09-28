#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

using namespace std;

string encryptVigenere(const string& text, const string& key);
string decryptVigenere(const string& text, const string& key);

#endif // VIGENERE_H
