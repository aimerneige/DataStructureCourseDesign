OBJECTS = main.o
TARGET = maze
CC = gcc
CC_FLAG = -Wall
RM = rm
RM_FLAGS = -f

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CC_FLAG)

.PHONY: clean
clean:
	-$(RM) $(RM_FLAGS) $(OBJECTS) $(TARGET)
