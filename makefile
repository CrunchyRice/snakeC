CC = gcc
CFLAGS = -Wall -ansi -pedantic -Werror
EXEC = snake
OBJ = food.o grid.o messages.o movement.o random.o snakeMov.o terminal.o winLoseCondition.o main.o

ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE
UNBEATABLE : clean $(EXEC)
endif

$(EXEC):$(OBJ)
		$(CC) $(OBJ) -o $(EXEC)


food.o: food.c food.h random.h
		$(CC) $(CFLAGS) food.c -c

grid.o: grid.c grid.h food.h snakeMov.h terminal.h movement.h messages.h winLoseCondition.h
		$(CC) $(CFLAGS) grid.c -c

messages.o: messages.c messages.h
		$(CC) $(CFLAGS) messages.c -c

random.o: random.c random.h
		$(CC) $(CFLAGS) random.c -c

snakeMov.o: snakeMov.c snakeMov.h
		$(CC) $(CFLAGS) snakeMov.c -c

terminal.o: terminal.c terminal.o
		$(CC) $(CFLAGS) terminal.c -c

winLoseCondition.o: winLoseCondition.c winLoseCondition.h
		$(CC) $(CFLAGS) winLoseCondition.c -c



main.o: main.c grid.h
		$(CC) $(CFLAGS) main.c -c


clean:
		rm -f $(EXEC) $(OBJ)