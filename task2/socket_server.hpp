#pragma once
#include "socket.hpp"

class SocketServer: public Socket {
public:
	SocketServer(const string &host, int port): Socket(host, port) {}
	virtual ~SocketServer() {}
	void start(int max_connect);
	Socket accept();
};
