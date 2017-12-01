#include "socket_server.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void SocketServer::start(int max_connect) {
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(this->getPort());
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(this->getSocketId(), (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		throw "Cannot bind socket";
	}
	listen(this->getSocketId(), max_connect);
}

Socket SocketServer::accept() {
	return Socket(::accept(this->getSocketId(), NULL, NULL));
}
