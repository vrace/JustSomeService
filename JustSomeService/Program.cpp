#include "SomeServiceServer.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(0));
    
    SomeServiceServer server;
    
    if (!server.Init())
        return -1;
    
    server.Run();
    
    return 0;
}
