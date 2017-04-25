#include "HelloController.h"
#include <vector>
#include <sstream>

namespace
{
    const std::string SERVICE_PATH = "/hello";
}

HttpResponse* HelloController::Dispatch(const HttpRequest &request)
{
    RequestMethod method = request.GetMethod();
    const std::string &url = request.GetURL();
    
    if (url == SERVICE_PATH || url.find(SERVICE_PATH + '/') == 0)
    {
        std::vector<std::string> args;
        std::stringstream ss(url.substr(SERVICE_PATH.length()));
        
        std::string line;
        while (std::getline(ss, line, '/'))
        {
            if (!line.empty())
                args.push_back(line);
        }
        
        if (method == REQUEST_METHOD_GET && args.empty())
            return SayHello();
        
        if (method == REQUEST_METHOD_GET && args.size() == 1)
            return SayHello(args[0]);
    }
    
    return NULL;
}

HttpResponse* HelloController::SayHello()
{
    std::string payload = _service.SayHello();
    
    HttpHeader header;
    header["Content-Type"] = "text/plain";
    
    return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, payload);
}

HttpResponse* HelloController::SayHello(const std::string &name)
{
    std::string payload = _service.SayHello(name);
    
    HttpHeader header;
    header["Content-Type"] = "text/plain";
    
    return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, payload);
}
