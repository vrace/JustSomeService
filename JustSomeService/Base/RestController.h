#ifndef REST_CONTROLLER_H
#define REST_CONTROLLER_H

#include "HttpRequest.h"
#include "HttpResponse.h"
#include <vector>
#include <string>

class RestController
{
public:
    RestController();
    virtual ~RestController();
    
    virtual const std::string& GetRequestPath() const = 0;
    virtual HttpResponse* Dispatch(const HttpRequest &request) = 0;
    
protected:
    std::vector<std::string> GetRequestPathComponents(const HttpRequest &request);
};

#endif
