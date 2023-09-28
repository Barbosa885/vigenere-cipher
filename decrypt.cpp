#include <iostream>
#include <string>
#include "vigenere.h"

using namespace std;

string decryptVigenere(string text, string key)
{
  string decryptedText = "";
  int textLength = text.length();
  int keyLength = key.length();

  for (int i = 0; i < textLength; i++)
  {
    char encryptedChar = text[i];
    char keyChar = key[i % keyLength];
    char decryptedChar;

    if (isalpha(encryptedChar))
    {
      char base = islower(encryptedChar) ? 'a' : 'A';
      decryptedChar = ((encryptedChar - base) - (keyChar - base) + 26) % 26 + base;
    } else {
      decryptedChar = encryptedChar;
    }

    decryptedText += decryptedChar;
  }

  return decryptedText;
}

