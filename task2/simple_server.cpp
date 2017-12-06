#include <iostream>
#include "socket_server.hpp"
#include <cstdlib>
#include <cstring>

using namespace std;

void print_array(const char *buf, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%02X ", buf[i]);
	}
}

int main(int argc, char *argv[]) 
{
	string host;
	int port;
	if (argc == 2) {
		port = atoi(argv[1]);
		host = "127.0.0.1";
	}
	else if (argc == 3) {
		host = argv[1];
		port = atoi(argv[2]);
	}
	else {
		cerr << "Worng arguments\n";
		exit(1);
	}
	try {
		SocketServer server(host, port);
		server.start(1);
		Socket channel = server.accept();
		char buf[2048];
		bzero(buf, sizeof(buf));
		int read_bytes = channel.read((uint8_t*)buf, sizeof(buf));
		while (read_bytes > 0) {
			cout << "Read " << read_bytes << endl;
			print_array(buf, read_bytes);
			read_bytes = channel.read((uint8_t*)buf, sizeof(buf)); 
		}
		cout << endl;
	}
	catch (const char *msg) {
		cerr << msg << endl;
	}
	catch (...) {
		cerr << "ERROR\n";
	}
	exit(0);
}
