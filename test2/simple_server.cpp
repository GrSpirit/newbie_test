#include <iostream>
#include "socket_server.hpp"
#include <cstdlib>
#include <cstring>

using namespace std;

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
		cout << "Accept\n";
		Socket channel = server.accept();
		cout << "Read\n";
		char buf[1024];
		bzero(buf, sizeof(buf));
		channel.read((BYTE*)buf, sizeof(buf));
		cout << buf << endl;
	}
	catch (const char *msg) {
		cerr << msg << endl;
	}
	catch (...) {
		cerr << "ERROR\n";
	}
	exit(0);
}
