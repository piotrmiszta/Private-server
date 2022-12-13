//
// Created by programowanie on 04.12.22.
//

#ifndef CLIENTCPP_CONNECTIONS_H
#define CLIENTCPP_CONNECTIONS_H

#include <sys/socket.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
class connections {
private:
    struct sockaddr_in servAddress;
    const char* IPv4;
    int socketfd;
    int clientfd;
    struct in_addr ipClient;
public:
    connections();
    int Mconnect();
    int getClientFd() const {return clientfd;}
    int getSock() const {return socketfd;}
    int sendMessage(const char* text, int len) const;
    char* getMessage();
};


#endif //CLIENTCPP_CONNECTIONS_H
