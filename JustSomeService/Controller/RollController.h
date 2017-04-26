#ifndef RANDOM_CONTROLLER_H
#define RANDOM_CONTROLLER_H

#include "../Base/RestController.h"
#include "../Service/RollService.h"

class RollController : public RestController
{
public:
    virtual HttpResponse* Dispatch(const HttpRequest &request);
    virtual const std::string& GetRequestPath() const;
    
private:
    HttpResponse* Roll();
    HttpResponse* Roll(const std::string &arg);
    HttpResponse* InvalidArgument(const std::string &text);
    HttpResponse* BuildResponse(HttpStatusCode statusCode, const std::string &payload);
    
private:
    RollService _service;
};

#endif
