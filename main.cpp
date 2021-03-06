#include <iostream>
#include "IRC.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <vector>

using namespace std;

class Connection {
public:
    int port;
    string username, nickname, address, password, ircName;
};

//void Connection::establishConnection(void){
//}

float tempConvert(float inTemp, string convertWay) {
    if (convertWay == "celcius") {
        return (inTemp * 9/5) + 32;
    } else if (convertWay == "fahreheit") {
        return (inTemp - 32) * 5/9;
    } else {
        return 0
    }

}
int checkCommand(string inStr){
    string subInStr = inStr.substr(0,8);
    std::vector<string> commandList = {"quit", "motd"};
    if (subInStr == "MalleBot"){
        int i = 0;
        // Fix for loop so that range based loop is not used.
        for (int n : commandList){
            // check if command is present in following letters
            string potentialCommand = n.substr(8, commandList.length());
            // Execute command if present
            if (potentialCommand == n){
                // make an array with pointers to external functions?
                functionPointer[i];
                i++;
            } else {
                i++;
            }
        }
    }
}
int post_Entry(char* params, irc_reply_data* hostd, void* conn){

    IRC* irc_conn=(IRC*)conn;

    irc_conn->join("#testMalle");
    return 0;
}

// Function will respond to a ping request by irc server with a pong
void pingPong(string serverIP){
    int IRC::privmsg(serverIP, "Pong");
}
// getData asks user for irc data and returns a Connection class with the data.
Connection getData()
{
    int port;
    string username, nickname, address, password, ircName;
    Connection getData_connection;

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

    // make the returned class

    getData_connection.address = address;
    getData_connection.port = port;
    getData_connection.nickname = nickname;
    getData_connection.password = password;
    getData_connection.ircName = ircName;
    getData_connection.username = username;

    // Return class of given information
    return getData_connection;
}
int main()
{
    IRC conn;

    // according to docs, required to initialise winsock
    /* {
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(1,1), &wsaDATA))
    {
        printf("Failed to initialize winsock \n");
    } }
    */

    Connection requestResult = getData();

    //conn.hook_irc_command("PONG", &FILLERFUNCT)

    conn.hook_irc_command("JOIN", post_Entry);
    conn.start(requestResult.address, requestResult.port, requestResult.nickname,
               requestResult.username, requestResult.ircName, requestResult.password);

    // create child process to work at same time as message_loop()
    // ERROR: Fork() is not defined in scope  - Might be problem with compiler.
    pid_t pid = fork();
    if (pid == 0){
        // Child process
        if (VARFORMESSAGE == "PING"){
            pingPong(requestResult.address);
        }
    } else if (pid > 0){
        // Parent Process
    } else {
        cout << "Fork failed";
        return 0;
        }
    conn.message_loop();
    //WSACleanup();
}
