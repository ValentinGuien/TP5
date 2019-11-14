CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lm
EXEC = mastermind
OBJ = master.o master_texte.o

all: $(EXEC)
	

mastermind: master.o master_texte.o
	$(CC) -o mastermind master.o master_texte.o $(CFLAGS) $(LDFLAGS)

master.o: master.c
	$(CC) -o master.o -c master.c $(CFLAGS) $(LDFLAGS)

master_texte.o: master_texte.c master.h
	$(CC) -o master_texte.o -c master_texte.c $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
