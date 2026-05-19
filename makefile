CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/quiz.c src/ranking.c src/arquivo.c src/utils.c

OUT = quiz.out

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)