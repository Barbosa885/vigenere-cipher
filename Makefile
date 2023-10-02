# Makefile
CC = g++
CFLAGS = -Wall -g

# Alvo principal que depende de cipher.o
main: cipher.o attack.o
	$(CC) $(CFLAGS) -o run cipher.o attack.o

# Alvo para o arquivo objeto cipher.o
cipher.o: cipher.cpp attack.cpp
	$(CC) $(CFLAGS) -c cipher.cpp attack.cpp

# Alvo para limpar os arquivos compilados
clean:
	rm -f *.o main
