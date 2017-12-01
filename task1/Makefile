CC = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I ../common/
OBJ = test1.o ../common/message.o

all: test1

test1: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(INCLUDE)

#%.o: %.c %.h %.cpp %.hpp $(DEPS)
.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

clean:
	@rm -f test1 *.o ../common/*.o

