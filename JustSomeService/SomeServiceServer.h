#ifndef SOME_SERVICE_SERVER_H
#define SOME_SERVICE_SERVER_H

#include "Network/BSDSocketRestServer.h"

class SomeServiceServer : public BSDSocketRestServer
{
public:
    virtual bool Init();
};

#endif
