#ifndef HELLO_CONTROLLER_H
#define HELLO_CONTROLLER_H

#include "../Base/RestController.h"
#include "../Service/HelloService.h"

class HelloController : public RestController
{
public:
    virtual HttpResponse* Dispatch(const HttpRequest &request);
    
private:
    HttpResponse* SayHello();
    HttpResponse* SayHello(const std::string &name);
    
private:
    HelloService _service;
};

#endif
