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

    if (letterText == ' ')
    {
      cipherText += ' ';
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

int main()
{
  string text, key;
  cout << "Enter the text to be encrypted: ";
  getline(cin, text);
  cout << "Enter the key: ";
  getline(cin, key);

  string cipherText = cipher(text, key);
  cout << "Cipher Text: " << cipherText << endl;
  return 0;
}
