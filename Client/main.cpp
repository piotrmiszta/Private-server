#include "connections.h"
#include <string>
#include <iostream>
#include <cstring>
#define PORT 8080



int main(int argc, char const* argv[])
{
    char* hi = "HI\n";
    connections con;
    con.Mconnect();
    con.sendMessage(hi, strlen(hi));
    std::cout << con.getMessage();
    return 0;
}
