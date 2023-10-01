#include <map>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

string frequencyAnalysis(string cipherText)
{
  // Converte o texto para maiúsculas
  transform(cipherText.begin(), cipherText.end(), cipherText.begin(), ::toupper);

  // Conta a frequência de cada letra
  map<char, int> freqMap;
  for (char c: cipherText)
  {
    if (isalpha(c) )
    {
      freqMap[c]++;
    }
  }

  // Ordena as letras por frequência
  vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
  sort(freqVec.begin(), freqVec.end(), [](auto &left, auto &right) {
    return left.second > right.second;
  });

  // A chave é a ordem das letras com base na frequência
  string key = "";
  for (auto &p: freqVec)
  {
    key += p.first;
  }

  return key;
}
