#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include "vigenere.h"
#include <cstdlib>
#include <vector>

using namespace std;

void clearTerminal()
{
  system("cls");
  system("clear");
}

string cipher(string text, string key)
{
  // Variável que armazena o texto cifrado
  string cipherText = "";

  // Repete a chave até que ela tenha o mesmo tamanho do texto
  while(key.size() < text.size())
  {
    key += key;
  }

  // Percorre o texto e a chave
  int j = 0;
  for(string::size_type i = 0; i < text.size(); i++)
  {
    char letterText = text[i];

    // Ignora caracteres que não são letras do alfabeto
    if (!isalpha(letterText))
    {
      continue;
    }

    // Ignora espaços no texto plano
    if (letterText == ' ')
    {
      cipherText += letterText;
      continue;
    }

    // Ignora caracteres especiais
    if (letterText == '!' || letterText == '?' || letterText == '.' || letterText == ',')
    {
      cipherText += letterText;
      continue;
    }

    // Pega a letra da chave 
    char letterKey = key[j % key.size()];

    // Transforma as letras em maiúsculas
    letterText = toupper(letterText);
    letterKey = toupper(letterKey);

    // Cifra a letra do texto com a letra da chave e armazena na variável cipherText
    char letterCipher = ((letterText - 'A') + (letterKey - 'A')) % 26 + 'A';
    cipherText += letterCipher;

    // Incrementa o contador da chave para pegar a próxima letra
    j++;
  }
  return cipherText;
}

string decipher(string cipherText, string key)
{
  // Variável que armazena o texto decifrado
  string decipherText = "";

  // Repete a chave até que ela tenha o mesmo tamanho do texto
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

    // Ignora caracteres especiais
    if (letterCipher == '!' || letterCipher == '?' || letterCipher == '.' || letterCipher == ',')
    {
      cipherText += letterCipher;
      continue;
    }

    // Pega a letra da chave 
    char letterKey = key[j % key.size()];

    // Transforma as letras em maiúsculas
    letterCipher = toupper(letterCipher);
    letterKey = toupper(letterKey);

    // Decifra a letra do texto com a letra da chave e armazena na variável decipherText
    char letterDecipher = ((letterCipher - letterKey  + 26) % 26) + 'A';
    decipherText += letterDecipher;

    // Incrementa o contador da chave para pegar a próxima letra
    j++;
  }
  return decipherText;
}

int main()
{
  string option;
  cout << "Escolha uma opção: " << endl;
  cout << "1 - Cifrar" << endl;
  cout << "2 - Decifrar (com quebra de senha)" << endl;
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

    else if (option == "n" || option == "N") 
    {
      string cipherText;
      cout << "Escreva o texto cifrado: ";
      getline(cin, cipherText);
      string key = quebrar_senha_kasiski(cipherText);
      cout << "Chave utilizada: " << key << endl;
      string decipherText = decipher(cipherText, key);
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

