#include "HelloService.h"

std::string HelloService::SayHello()
{
    return "Hello!";
}

std::string HelloService::SayHello(const std::string &name)
{
    return "Hello " + name + "!";
}
