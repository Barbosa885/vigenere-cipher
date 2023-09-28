#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

string encryptVigenere(std::string text, std::string key)
{
  string encryptedText = "";
  int textLength = text.length();
  int keyLength = key.length();

  for (int i = 0; i < textLength; i++)
  {
    char textChar = text[i];
    char keyChar = key[i % keyLength];
    char encryptedChar;

    if (isalpha(textChar))
    {
      char base = islower(textChar) ? 'a' : 'A';
      encryptedChar = ((textChar - base + keyChar - 'A') % 26) + base;
    } else 
    {
      encryptedChar = textChar;
    }
  encryptedText += encryptedChar;
  }
  return encryptedText;
}
