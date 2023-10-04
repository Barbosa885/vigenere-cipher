# Makefile
all: compile run
	
compile:
	g++ -o run cipher.cpp

run:
	./run

clean: 
	del run.exe
