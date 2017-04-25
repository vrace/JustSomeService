#include "Network/BSDSocketRestServer.h"

int main()
{
    BSDSocketRestServer server;
    
    if (!server.Init())
        return -1;
    
    server.Run();
    
    return 0;
}
