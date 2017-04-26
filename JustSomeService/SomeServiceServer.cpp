#include "SomeServiceServer.h"
#include "Controller/HelloController.h"
#include "Controller/RollController.h"

bool SomeServiceServer::Init()
{
    AddController(new HelloController());
    AddController(new RollController());
    
    return BSDSocketRestServer::Init();
}
