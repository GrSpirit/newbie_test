#include "socket.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <algorithm>
#include <iostream>

Socket::Socket(const string &host, int port) : _host(host), _port(port) {
	_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock < 0) {
		throw "Cannot create socket";
	}
}

Socket::~Socket() {
	close(_sock);
}

int Socket::getPort() const {
	return _port;
}

string Socket::getHost() const {
	return _host;
}
int Socket::getSocketId() const {
	return _sock;
}

void Socket::write(const BYTE *data, size_t len) {
	int res = send(_sock, data, len, 0);
	if (res < 0) {
		throw "Cannot send message";
	}
}

int Socket::read(BYTE *data, size_t max_len) {
	int read_bytes = recv(_sock, data, max_len, 0);
	if (read_bytes < 0) {
		throw "Cannot receive message";
	}

	return read_bytes;
}
