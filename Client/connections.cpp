//
// Created by programowanie on 04.12.22.
//

#include "connections.h"

#define DEBUG

connections::connections() {
    servAddress.sin_family = AF_INET;
    servAddress.sin_port = htons(8080);
    socketfd = 0;
    IPv4 = "127.0.0.1";
}

int connections::Mconnect() {
    if ((socketfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout<< "\n Socket creation error \n";
        return -1;
    }
    if (inet_pton(AF_INET, this->IPv4, &servAddress.sin_addr) <= 0) {
        std::cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }
    if ((clientfd = connect(socketfd, (struct sockaddr*)&servAddress, sizeof(servAddress))) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }


    return 0;
}

int connections::sendMessage(const char *text, const int len) const {
    send(socketfd, text, len, 0);
#ifdef DEBUG
    std::cout<<"[D]SEND: " << text << "\n";
#endif
    return 0;
}

char* connections::getMessage() {
    char* buffer = new char[1024];
    read(socketfd, buffer, 1024);
#ifdef DEBUG
    std::cout << "[D]SERVER: " << buffer << "\n";
#endif
    return buffer;
}

