CC = g++
CFLAGS = -Wall
COBJ = test1.o memory_buf.o

all: test1

test1: $(COBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h %.cpp %.hpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f test1 *.o

