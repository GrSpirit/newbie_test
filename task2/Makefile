CC = g++
CFLAGS = -Wall -std=c++11
INCLUDE = -I../common/
C_SRC = task2_client.cpp socket.cpp socket_client.cpp ../common/message.cpp
C_OBJ = $(C_SRC:.cpp=.o)
S_SRC = socket.cpp socket_server.cpp simple_server.cpp
S_OBJ = $(S_SRC:.cpp=.o)

all: task2_test simple_server

task2_test: $(C_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

simple_server: $(S_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDE)

clean:
	@rm -f task2_test simple_server *.o

