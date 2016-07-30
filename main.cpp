#include <iostream>
#include "IRC.h"
#include <windows.h>



using namespace std;

class Connection {
public:
    int port;
    string username, realname, address;
};

//void Connection::establishConnection(void){
//}

void post_entry(char* params, irc_reply_data* hostd, void* conn){

    IRC* irc_conn=(IRC*)conn;

    irc_conn->join("#testMalle");
    return 0;
}
// ERROR: Must be fixed to return an array
int* getData()
{
    int port;
    string username, nickname, address, password, ircName;

    // input connection details for IRC (also should put in fail testing for each field)
    std::cout << "Enter details" << endl;
    std::cout << "Enter your Username: " << endl;
    cin >> username;
    std::cout << "Enter your Nick Name: " << endl;
    cin >> nickname;
    std::cout << "Enter your server address: " << endl;
    cin >> address;
    std::cout << "Enter your port: " << endl;
    cin >> port;
    std::cout << "Enter password:" << endl;
    cin >> password;
    std::cout << "Enter ircName:" << endl;
    cin >> ircName;

    // Return array of given information
    // ERROR: Function cannot return array.
    return {username,nickname,address,port,password,ircName};
}
void main()
{
    IRC conn;

    // according to docs, required to initialise winsock
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(1,1), &wsaDATA))
    {
        printf("Failed to initialize winsock \n");
    }
    requestResult = getData()

    //conn.hook_irc_command("PONG", &FILLERFUNCT)

    conn.hook("JOIN", post_Entry);
    conn.start();
    conn.message_loop();
    WSACleanup();
}
