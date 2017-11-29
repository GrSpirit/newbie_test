#pragma once
#include "socket.hpp"
#include <string>
using namespace std;

class SocketClient: public Socket {
public:
	SocketClient(const string &host, int port) : Socket(host, port) { }
	void connect();
};
