#include "BSDSocketRestServer.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

namespace
{
    const std::string SERVER_PORT = "17123";
    const int SERVER_RECV_SIZE = 1048576 * 10;
    
    addrinfo* GetServerAddrInfo(const std::string &serverPort)
    {
        addrinfo hint, *info;
        
        memset(&hint, 0, sizeof(hint));
        
        hint.ai_family = AF_INET;
        hint.ai_socktype = SOCK_STREAM;
        hint.ai_protocol = IPPROTO_TCP;
        hint.ai_flags = AI_PASSIVE;
        
        getaddrinfo(NULL, serverPort.c_str(), &hint, &info);
        
        return info;
    }
}

BSDSocketRestServer::BSDSocketRestServer()
: _listenfd(-1)
{
    
}

BSDSocketRestServer::~BSDSocketRestServer()
{
    
}

bool BSDSocketRestServer::Init()
{
    addrinfo *addr = GetServerAddrInfo(GetServerPort());
    
    if (!addr)
        return false;
    
    int fd = -1;
    _listenfd = -1;
    
    do
    {
        fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
        
        if (fd == -1)
            break;
        
        if (bind(fd, addr->ai_addr, addr->ai_addrlen) == -1)
            break;
        
        if (listen(fd, SOMAXCONN) == -1)
            break;
        
        _listenfd = fd;
        _recvbuf.resize(GetServerRecvSize());
        
    } while(0);
    
    freeaddrinfo(addr);
    
    if (_listenfd != fd)
        close(fd);
    
    return _listenfd != -1;
}

void BSDSocketRestServer::Run()
{
    while (_listenfd != -1)
    {
        int clientfd = accept(_listenfd, NULL, NULL);
        
        if (clientfd == -1)
            continue;
        
        ssize_t received = recv(clientfd, &_recvbuf[0], GetServerRecvSize(), 0);
        
        if (received > 0)
        {
            std::string request(&_recvbuf[0], received);
            std::string response = Dispatch(request);
            send(clientfd, response.c_str(), response.length(), 0);
        }
        
        close(clientfd);
    }
}

void BSDSocketRestServer::Shutdown()
{
    close(_listenfd);
    _listenfd = -1;
}

const std::string& BSDSocketRestServer::GetServerPort() const
{
    return SERVER_PORT;
}

int BSDSocketRestServer::GetServerRecvSize() const
{
    return SERVER_RECV_SIZE;
}
