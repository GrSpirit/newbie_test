#include "socket_client.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//extern "C" int connect(int sockfd, const struct sockaddr *addr,
//                   socklen_t addrlen); 

void SocketClient::connect() {
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_port = htons(this->getPort());
	addr.sin_addr.s_addr = inet_addr(this->getHost().c_str());
	
	if (::connect(this->getSocketId(), (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		throw string("Cannot connect");
	}
}
