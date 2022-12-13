//
// Created by programowanie on 10.12.22.
//

#ifndef UNTITLED_CONNECTION_H
#define UNTITLED_CONNECTION_H
#include <netinet/in.h>
#include <stdio.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

class connection {
private:
    int server_fd;
    int socket_fd;
    int valread;
    struct sockaddr_in address;
public:
    connection();
    int mbind();
    int mlisten();
    int con();
    char* mread();
    void msend(const char* text, int size);
    void mclose();
};


#endif //UNTITLED_CONNECTION_H
