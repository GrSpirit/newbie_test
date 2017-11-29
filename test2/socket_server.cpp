#include "socket_server.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void SocketServer::start(int max_connect) {
	listen(this->getSocketId(), max_connect);
}

Socket SocketServer::accept() {
	return Socket(::accept(this->getSocketId(), NULL, NULL));
}
