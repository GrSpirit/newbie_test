CC = g++
CFLAGS = -Wall
COBJ = task2_test.o socket.o socket_client.o memory_buf.o message.o
SOBJ = socket.o socket_server.o simple_server.o

all: task2_test simple_server

task2_test: $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^

simple_server: $(SOBJ)
	$(CC) $(CFLAGS) -o $@ $^

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f task2_test simple_server *.o

