#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "socket_client.hpp"
#include "types.h"
#include "message.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3) {
		cerr << "Wrong number of arguments\n";
		cerr << "Usage: task2_test ipaddr port\n";
		exit(1);
	}
	SocketClient client(argv[1], atoi(argv[2]));
	try {
		client.connect();
		MemoryBuf buff = make_message(cin);
		cout << "Sending " << buff.size() << " bytes\n";
		client.write((const BYTE*)buff.data(), buff.size());
	}
	catch(string msg) {
		cerr << msg << endl;
		exit(1);
	}
	
	exit(0);
}
