#include "RollController.h"
#include <stdlib.h>
#include <sstream>

const std::string& RollController::GetRequestPath() const
{
    static std::string requestPath = "/roll";
    return requestPath;
}

HttpResponse* RollController::Dispatch(const HttpRequest &request)
{
    RequestMethod method = request.GetMethod();
    RequestURL url = request.GetURL(GetRequestPath());
    
    if (url)
    {
        if (method == REQUEST_METHOD_GET && url.GetComponentSize() == 0)
            return Roll();
        
        if (method == REQUEST_METHOD_GET && url.GetComponentSize() == 1)
            return Roll(url[0]);
    }
    
    return NULL;
}

HttpResponse* RollController::BuildResponse(HttpStatusCode statusCode, const std::string &payload)
{
    HttpHeader header;
    header["Content-Type"] = "text/plain";
    
    return new HttpResponse(HttpStatus(statusCode), header, payload);
}

HttpResponse* RollController::InvalidArgument(const std::string &text)
{
    std::stringstream ss;
    ss << "An integer between 1 and " << RAND_MAX << " is expected, but received " << text;
    
    return BuildResponse(HTTP_STATUS_BAD_REQEUST, ss.str());
}

HttpResponse* RollController::Roll()
{
    std::stringstream ss;
    ss << "ROLL (1 - 100)" << std::endl;
    ss << 1 + rand() % 100 << std::endl;
    
    return BuildResponse(HTTP_STATUS_OK, ss.str());
}

HttpResponse* RollController::Roll(const std::string &arg)
{
    char *ep;
    int maxval = (int)strtol(arg.c_str(), &ep, 10);
    
    if (*ep || maxval <= 1 || maxval > RAND_MAX)
        return InvalidArgument(arg);
    
    std::stringstream ss;
    ss << "ROLL (1 - " << maxval << ")" << std::endl;
    ss << 1 + rand() % maxval << std::endl;
    
    return BuildResponse(HTTP_STATUS_OK, ss.str());
}
