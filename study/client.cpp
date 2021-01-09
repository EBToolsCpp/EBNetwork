//
// Created by LQYHE on 2021/1/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string>


int main(int argc,char* argv[])
{
    int sock;
    sockaddr_in serv_addr;
    char message[30] = {0};
    int str_len;
    std::string ip = "127.0.0.1";
    int port = 2234;
    sock = socket(PF_INET,SOCK_STREAM,0);
    if(sock == -1)
    {
        return -1;
    }
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip.c_str());
    serv_addr.sin_port= htons(port);
    if(connect(sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1)
    {
        return -2;
    }
    str_len = read(sock,message,sizeof(message)-1);
    if(str_len == -1)
    {
        return -3;
    }
    printf("message is :%s\n",message);
    close(sock);
    return 0;
}