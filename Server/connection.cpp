//
// Created by programowanie on 10.12.22.
//

#include "connection.h"
#include <iostream>
#define DEBUG
connection::connection() {
    int opt=1;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET,SO_REUSEADDR | SO_REUSEPORT, &opt,sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
}

int connection::mbind() {
    if (bind(server_fd, (struct sockaddr*)&address,sizeof(address)) < 0) {
        perror("bind failed");
        return -1;
    }
    return 0;
}

int connection::mlisten() {
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return -1;
    }
    return 0;
}

int connection::con() {
    size_t size = sizeof(address);
    if ((socket_fd = accept(server_fd, reinterpret_cast<struct sockaddr*>(&address), reinterpret_cast<socklen_t*>(&size)))
        < 0) {
        perror("accept");
        return -1;
    }

#ifdef DEBUG
    auto pClientIp = reinterpret_cast<struct sockaddr_in*>(&address);
    struct in_addr ipAddr = pClientIp->sin_addr;
    char str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &ipAddr, str, INET_ADDRSTRLEN);
    std::cout << "[D] Client with IP: " << str << "\n";
#endif
    return 0;
}

char *connection::mread() {
    char* buff = new char[1024];
    read(socket_fd, buff, 1024);
#ifdef DEBUG
    std::cout << "[D] RECEIVING: " << buff << "\n";
#endif
    return buff;

}

void connection::msend(const char *text, int size) {
    send(socket_fd, text, size, 0);
#ifdef DEBUG
    std::cout << "[D] SEND: " << text << "\n";
#endif
}

void connection::mclose() {
    close(socket_fd);
}
