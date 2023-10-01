#include <iostream>
#include <string>

using namespace std;

string cipher(string text, string key)
{
  string cipherText = "";
  
  while(key.length() < text.length())
  {
    key += key;
  }

  int j = 0;
  for(int i = 0; i < text.length(); i++)
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

    char letterKey = key[j % key.length()];

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
  for(int i = 0; i < cipherText.length(); i++)
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

    char letterKey = key[j % key.length()];

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
  string opcao;
  cout << "Escolha uma opção: " << endl;
  cout << "1 - Cifrar" << endl;
  cout << "2 - Decifrar" << endl;
  getline(cin, opcao);

  if (opcao == "1")
  {
    string text, key;
    cout << "Escreva o texto à ser codificado: ";
    getline(cin, text);
    cout << "Escreva uma chave: ";
    getline(cin, key);
    string cipherText = cipher(text, key);
    cout << "Texto cifrado: " << cipherText << endl;
  }
  else if (opcao == "2")
  {
    string cipherText, key;
    cout << "Escreva o texto cifrado: ";
    getline(cin, cipherText);
    cout << "Escreva uma chave: ";
    getline(cin, key);
    string decipherText = decipher(cipherText, key);
    cout << "Texto decifrado: " << decipherText << endl;
  }
  else
  {
    cout << "Opção inválida!" << endl;
  }

  return 0;
}
