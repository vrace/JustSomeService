#include "SomeServiceServer.h"

int main()
{
    SomeServiceServer server;
    
    if (!server.Init())
        return -1;
    
    server.Run();
    
    return 0;
}
