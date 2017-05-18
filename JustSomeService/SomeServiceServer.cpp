#include "SomeServiceServer.h"
#include "Controller/HelloController.h"
#include "Controller/RollController.h"
#include "Controller/MenuController.h"

bool SomeServiceServer::Init()
{
    AddController(new HelloController());
    AddController(new RollController());
    AddController(new MenuController());
    
    return BSDSocketRestServer::Init();
}
