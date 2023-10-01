#include <iostream>
#include <string>
#include "vigenere.h"
#include <cstdlib>

using namespace std;

void clearTerminal()
{
  system("cls");
  system("clear");
}

string cipher(string text, string key)
{
  string cipherText = "";
  
  while(key.size() < text.size())
  {
    key += key;
  }

  int j = 0;
  for(string::size_type i = 0; i < text.size(); i++)
  {
    char letterText = text[i];

    // Ignora caracteres que não são letras
    if (!isalpha(letterText))
    {
      continue;
    }

    // Ignora espaços no texto plano
    if (letterText == ' ')
    {
      continue;
    }

    char letterKey = key[j % key.size()];

    letterText = toupper(letterText);
    letterKey = toupper(letterKey);

    char letterCipher = ((letterText - 'A') + (letterKey - 'A')) % 26 + 'A';

    cipherText += letterCipher;

    j++;
  }
  return cipherText;
}

string decipher(string cipherText, string key)
{
  string decipherText = "";
  int j = 0;
  for(string::size_type i = 0; i < cipherText.size(); i++)
  {
    char letterCipher = cipherText[i];

    // Ignora caracteres que não são letras
    if (!isalpha(letterCipher))
    {
      continue;
    }

    // Ignora espaços no texto cifrado
    if (letterCipher == ' ')
    {
      continue;
    }

    char letterKey = key[j % key.size()];

    letterCipher = toupper(letterCipher);
    letterKey = toupper(letterKey);

    char letterDecipher = ((letterCipher - letterKey  + 26) % 26) + 'A';

    decipherText += letterDecipher;

    j++;
  }
  return decipherText;
}

int main()
{
  string option;
  cout << "Escolha uma opção: " << endl;
  cout << "1 - Cifrar" << endl;
  cout << "2 - Decifrar" << endl;
  getline(cin, option);
  clearTerminal();

  if (option == "1")
  {
    string text, key;
    cout << "Escreva o texto à ser codificado: ";
    getline(cin, text);
    cout << "Escreva uma chave: ";
    getline(cin, key);
    string cipherText = cipher(text, key);
    cout << "Texto cifrado: " << cipherText << endl;
  }
  else if (option == "2")
  {
    cout << "Sabe a chave para a decodificação? (y/n) " << endl;

    getline(cin, option);
    clearTerminal();
    if (option == "y" || option == "Y")
    {
      string cipherText, key;
      cout << "Escreva o texto cifrado: ";
      getline(cin, cipherText);
      cout << "Escreva a chave: ";
      getline(cin, key);
      string decipherText = decipher(cipherText, key);
      cout << "Texto decifrado: " << decipherText << endl;
    }

    else if (option == "n" || option == "N") {
      string cipherText;
      cout << "Escreva o texto cifrado: ";
      getline(cin, cipherText);
      string decipherText = frequencyAnalysis(cipherText);
      cout << "Texto decifrado: " << decipherText << endl;
    } 
    else {
      cout << "Opção inválida!" << endl;
    }
  }
  else {
    cout << "Opção inválida!" << endl;
  }

  return 0;
}
