CC = gcc
CFLAGS = -W -Wall
TARGET = instrument
OBJECTS = main.c project.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
	
clean :
	rm *.o instrument
