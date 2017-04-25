#ifndef HELLO_SERVICE_H
#define HELLO_SERVICE_H

#include <string>

class HelloService
{
public:
    std::string SayHello();
    std::string SayHello(const std::string &name);
};

#endif
