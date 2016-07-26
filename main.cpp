#include <iostream>
#include "IRC.h"

IRC conn;

using namespace std;

class Connection {
public:
    int port;
    string username, realname, address;
};

void Connection::establishConnection(void){
}

int getData()
{
    int port;
    string username, realname, address;

    std::cout << "Enter details" << endl;
    std::cout << "Enter your Username: ";
    cin >> username;
    std::cout << "Enter your Real Name: ";
    cin >> realname;
    std::cout << "Enter your address: ";
    cin >> address;
    std::cout << "Enter your port: ";
    cin >> port;
    return [username,realname,address,port];
}
int main()
{
    requestResult = getData()
    return 0;
}
