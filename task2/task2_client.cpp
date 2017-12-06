#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "socket_client.hpp"
#include "types.h"
#include "message.hpp"

using namespace std;
#define MAX_BUFFER 1024

int main(int argc, char* argv[])
{
	char buff[MAX_BUFFER];
	if (argc != 3) {
		cerr << "Wrong number of arguments\n";
		cerr << "Usage: task2_test ipaddr port\n";
		exit(1);
	}
	SocketClient client(argv[1], atoi(argv[2]));
	try {
		client.connect();
		while (true) {
			MemoryBuf mess = make_message(cin);
			cout << "Sending " << mess.size() << " bytes...\n";
			client.write((const BYTE*)mess.data(), mess.size());
			memset(buff, 0, sizeof(buff));
			client.read((BYTE*)buff, sizeof(buff));
			cout << buff << endl;
		}
	}
	catch(string msg) {
		cerr << msg << endl;
		exit(1);
	}
	
	exit(0);
}
