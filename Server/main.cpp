#include <iostream>
#include <cstring>
#include "connection.h"

int main(int argc, char const* argv[])
{
    connection Con;
    Con.mbind();
    Con.mlisten();
    while(1) {
        Con.con();
        char* buff = Con.mread();

        const char* text = "hi";
        Con.msend(text, strlen(text));
    }
    Con.mclose();
    return 0;
}
