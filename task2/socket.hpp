#pragma once
#include <string>
#include <vector>
#include "types.h"

using namespace std;

class Socket {
	string _host;
	int _port;
	int _sock;
public:
	Socket(const string &host, int port);
	Socket(int sock) : _sock(sock) {}
	virtual ~Socket();
	int getPort() const;
	string getHost() const;
	int getSocketId() const;
	void write(const BYTE *data, size_t len);
	int read(BYTE *data, size_t max_len);
};
