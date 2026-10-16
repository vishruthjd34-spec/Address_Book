CC     = gcc
CFLAGS = -Wall
TARGET = addressbook
SRC    = main.c contact.c file.c populate.c

all: $(TARGET)

$(TARGET): $(SRC) contact.h file.h populate.h
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) a.out *.o

.PHONY: all run clean
