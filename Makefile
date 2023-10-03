CC = gcc
CFLAGS = -Wall -g
SRC = main.c task_manager.c fileio.c
OBJ = $(SRC:.c=.o)
EXECUTABLE = main.exe

$(EXECUTABLE): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXECUTABLE)