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
    int serv_sock;
    int clnt_sock;

    sockaddr_in serv_addr = {0};
    sockaddr_in clnt_addr = {0};
    socklen_t cln_addr_size;
    serv_sock = socket(PF_INET,SOCK_STREAM,0);
    if(serv_sock == -1)
        return -1;
    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(2234);
    if(bind(serv_sock,(sockaddr*)&serv_addr,sizeof(serv_addr)) == -1)
    {
        return -2;
    }
    if(listen(serv_sock,5) == -1)
    {
        return -3;
    }
    cln_addr_size= sizeof(clnt_addr);
    clnt_sock = accept(serv_sock,(sockaddr*)&clnt_addr,&cln_addr_size);
    if(clnt_sock == -1)
    {
        return -4;
    }
    char message[30] = {0};
    strcpy(message,"Hello Network");
    write(clnt_sock,message,sizeof(message));
    close(clnt_sock);
    close(serv_sock);
}