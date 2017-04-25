#include "SomeServiceServer.h"
#include "Controller/HelloController.h"

bool SomeServiceServer::Init()
{
    AddController(new HelloController());
    return BSDSocketRestServer::Init();
}
