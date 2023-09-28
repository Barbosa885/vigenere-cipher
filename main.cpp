#include <iostream>
#include "vigenere.h"

  using namespace std;

  int main()
  {
    string choice;

    cout << "Escolha uma opção: " << endl << "1 - Criptografar" << endl << "2 - Descriptografar" << endl;
  cin >> choice;

  if (choice == "1") 
  {
    string text, key;
    cout << "Digite o texto a ser criptografado: ";
    cin.ignore();
    cin >> text;

    cout << "Digite a chave: ";
    cin >> key;

    string encryptText = encryptVigenere(text, key);
    cout << "Texto criptografado: " << encryptText << endl;
  } else if (choice == "2")
  {
    string text, key;
    cout << "Digite o texto a ser descriptografado: ";
    cin.ignore();
    cin >> text;

    cout << "Digite a chave: ";
    cin >> key;

    string decryptText = decryptVigenere(text, key);
    cout << "Texto descriptografado: " << decryptText << endl;
  } else 
  {
    cout << "Opção inválida!" << endl;
  }

  return 0;
}
