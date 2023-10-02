# Makefile
CC = g++
CFLAGS = -Wall -g

# Alvo principal que depende de cipher.o
main: cipher.o 
	$(CC) $(CFLAGS) -o run cipher.o

# Alvo para o arquivo objeto cipher.o
cipher.o: cipher.cpp 
	$(CC) $(CFLAGS) -c cipher.cpp 

# Alvo para limpar os arquivos compilados
clean:
	rm -f *.o main
