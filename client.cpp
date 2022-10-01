#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "ImageToBin.cpp"

using namespace std;

//void ImageToBin(string imageName);

int main(){

    //Create Socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        cerr<< "Can't create a socket";
        return -1;
    }

    //Create a hint structure for the server
    int port = 54000;
    string ipAdress = "127.0.0.1";
    
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAdress.c_str(), &hint.sin_addr);

    //Connect with the server
    int connectResult = connect(sock, (sockaddr*)&hint, sizeof(sockaddr_in));

    if (connectResult == -1){
        cerr<< "Can't connect to a server";
        return -2;
    }

    char buf[4096];
    string userInput;

    //Enter the text
    cout << ">";
    getline(cin, userInput);

    //String parser variables
    string delimiter = "/";
    size_t pos = 0;
    string token;

    //Creation variables
    string filter;
    string path;
    string variation = "0,0";

    //String parser function
    int i=0;
    bool check = false;
    while((pos = userInput.find(delimiter)) != string::npos || i<3){

        token = userInput.substr(0, pos);
        if(i == 0){
            filter = token;
            if (filter == "G" || filter == "E"){
                check = true;
            }
        }else if (i == 1){
            path = token;
            if (check){
                break;
            }
        }else{
            variation = token;
        }

        userInput.erase(0, pos + delimiter.length());
        i++;
    }

    int sendFilter = send(sock, filter.c_str(), filter.size() + 1, 0);
    int sendVariation = send(sock, variation.c_str(), variation.size() + 1, 0);
    int sendPath = send(sock, path.c_str(), path.size()+1,0);


    do
    {

        //Wait for response
        memset(buf, 4096, 0);
        int bytesRecived = recv(sock, buf, 4096, 0);

        if (bytesRecived == -1){
            cerr<< "There was an error getting response from the server";
            continue;
        }else{
            //Display response
        cout<< "Server: " << string(buf, bytesRecived) << "\r\n";
        }

    } while (true);
    

    //Close socket
    close(sock);
    

    return 0;
}