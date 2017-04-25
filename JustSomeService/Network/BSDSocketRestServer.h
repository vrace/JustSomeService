#ifndef BSD_SOCKET_REST_SERVER_H
#define BSD_SOCKET_REST_SERVER_H

#include "../Base/RestServer.h"
#include <string>
#include <vector>

class BSDSocketRestServer : public RestServer
{
public:
    BSDSocketRestServer();
    virtual ~BSDSocketRestServer();
    
    virtual bool Init();
    void Run();
    void Shutdown();
    
protected:
    virtual const std::string& GetServerPort() const;
    virtual int GetServerRecvSize() const;
    
private:
    BSDSocketRestServer(const BSDSocketRestServer&);
    BSDSocketRestServer& operator =(const BSDSocketRestServer&);
    
private:
    int _listenfd;
    std::vector<char> _recvbuf;
};

#endif
