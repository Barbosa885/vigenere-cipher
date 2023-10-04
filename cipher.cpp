#include <algorithm>
#include <cctype>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Função para limpar o terminal
void clearTerminal()
{
  // Limpa o terminal no Windows
  system("cls");
  // Limpa o terminal no Unix/Linux
  system("clear");
}

// Função para cifrar o texto usando a cifra de Vigenere
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

    if(isalpha(letterText))
    {
      // Pega a letra da chave 
      char letterKey = key[j % key.size()];

      // Cifra a letra do texto com a letra da chave e armazena na variável cipherText
      char letterCipher;
      if(isupper(letterText))
      {
        // Cifra a letra maiúscula
        letterCipher = ((letterText - 'A') + (letterKey - 'A')) % 26 + 'A';
      } 
      else if(islower(letterText))
      {
        // Cifra a letra minúscula
        letterCipher = ((letterText - 'a') + (letterKey - 'a')) % 26 + 'a';
      } 

      // Adiciona a letra cifrada ao texto cifrado
      cipherText += letterCipher;
      // Incrementa o contador da chave para pegar a próxima letra
      j++;
    }
    else
    {
      // Copia o caractere que não é uma letra para o texto cifrado
      cipherText += letterText;
    }
  }

  return cipherText;
}

// Função para decifrar o texto usando a cifra de Vigenere
string decipher(string cipherText, string key)
{
  // Variável que armazena o texto decifrado
  string decipherText = "";

  // Repete a chave até que ela tenha o mesmo tamanho do texto
  int j = 0;
  for(string::size_type i = 0; i < cipherText.size(); i++)
  {
    char letterCipher = cipherText[i];
    
    if(isalpha(letterCipher))
    {
      // Pega a letra da chave 
      char letterKey = key[j % key.size()];

      // Decifra a letra do texto com a letra da chave e armazena na variável decipherText
      char letterDecipher;
      if(isupper(letterCipher))
      {
        // Decifra a letra maiúscula
        letterDecipher = ((letterCipher - letterKey  + 26) % 26) + 'A';
      }
      else if(islower(letterCipher))
      {
        // Decifra a letra minúscula
        letterDecipher = ((letterCipher - letterKey  + 26) % 26) + 'a';
      }

      // Adiciona a letra decifrada ao texto decifrado
      decipherText += letterDecipher;
      // Incrementa o contador da chave para pegar a próxima letra
      j++;
    }
    else
    {
      // Copia o caractere que não é uma letra para o texto decifrado
      decipherText += letterCipher;
    }
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

