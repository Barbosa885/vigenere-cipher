# Cifra e Decifra usando a Cifra de Vigenère

Este programa em C++ implementa a cifra e a decifra usando a Cifra de Vigenère. A Cifra de Vigenère é um método de criptografia que usa uma série de cifras de César com base em letras de uma senha. A cifra é fácil de entender e implementar e é baseada no uso de várias cifras de César em sequência, com diferentes valores de deslocamento ditados por uma "palavra-chave" [Source 12](https://www.geeksforgeeks.org/vigenere-cipher/).

A primeira parte do trabalho funciona de forma bem intuitiva com o que foi pedido, cifrar e decifrar usando a cifra de vigenère.

O programa começa com a inclusão das bibliotecas necessárias e a declaração do espaço de nomes `std`. Em seguida, ele define duas funções: `cipher` e `decipher`.

## Função cipher

A função `cipher` recebe dois parâmetros: `texto` e `chave`. Ela cria uma string vazia `cipherText` para armazenar o texto cifrado. Em seguida, ela repete a chave até que ela tenha o mesmo tamanho que o texto.

A função então entra em um loop que percorre cada caractere do texto. Se o caractere não for uma letra ou um espaço, ele é ignorado.

Se o caractere for uma letra, ele é convertido para maiúsculas e a letra correspondente da chave também é convertida para maiúsculas. A letra cifrada é calculada como o resultado da expressão `((letraTexto - 'A') + (letraChave - 'A')) % 26 + 'A'`. A letra cifrada é então adicionada ao `cipherText`.

Finalmente, a função retorna o `cipherText`.

## Função decipher

A função `decipher` é semelhante à função `cipher`, mas decifra o texto em vez de cifrá-lo. Ela recebe dois parâmetros: `cipherText` e `chave`. Ela cria uma string vazia `decipherText` para armazenar o texto decifrado.

A função então entra em um loop que percorre cada caractere do `cipherText`. Se o caractere não for uma letra ou um espaço, ele é ignorado.

Se o caractere for uma letra, ele é convertido para maiúsculas e a letra correspondente da chave também é convertida para maiúsculas. A letra decifrada é calculada como o resultado da expressão `((letterCipher - letterKey  + 26) % 26) + 'A'`. A letra decifrada é então adicionada ao `decipherText`.

Finalmente, a função retorna o `decipherText`.

## Função main

A função `main` é a função de entrada do programa. Ela começa solicitando ao usuário que escolha uma opção: cifrar ou decifrar.

Se a opção escolhida for cifrar, o programa solicita ao usuário que insira o texto e a chave. Em seguida, ele chama a função `cipher` para cifrar o texto e exibe o texto cifrado.

Se a opção escolhida for decifrar, o programa solicita ao usuário que insira o texto cifrado e a chave. Em seguida, ele chama a função `decipher` para decifrar o texto e exibe o texto decifrado.

Se a opção escolhida for inválida, o programa exibe uma mensagem de erro.

Finalmente, a função `main` retorna 0 para indicar que o programa terminou com sucesso.

