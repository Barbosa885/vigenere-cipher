# Makefile
CC = g++
CFLAGS = -Wall -g

# Alvo principal que depende de cipher.o
main: cipher.o frequency.o
	$(CC) $(CFLAGS) -o run cipher.o frequency.o

# Alvo para o arquivo objeto cipher.o
cipher.o: cipher.cpp frequency.cpp
	$(CC) $(CFLAGS) -c cipher.cpp frequency.cpp

# Alvo para limpar os arquivos compilados
clean:
	rm -f *.o main
