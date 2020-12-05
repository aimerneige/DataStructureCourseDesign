OBJECTS = main.o maze.o queue.o solve.o
TARGET = maze
CC = gcc
CC_FLAG = -Wall
RM = rm
RM_FLAGS = -f

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CC_FLAG)

ze: $(OBJECTS)
	$(CC) -o ze $(OBJECTS) $(CC_FLAGS)

.PHONY: clean
clean:
	-$(RM) $(RM_FLAGS) $(OBJECTS) $(TARGET)
