#include "HelloController.h"

namespace
{
    const std::string SERVICE_PATH = "/hello";
}

const std::string& HelloController::GetRequestPath() const
{
    return SERVICE_PATH;
}

HttpResponse* HelloController::Dispatch(const HttpRequest &request)
{
    RequestMethod method = request.GetMethod();
    RequestURL url = request.GetURL(SERVICE_PATH);
    
    if (url)
    {
        if (method == REQUEST_METHOD_GET && url.GetComponentSize() == 0)
            return SayHello();
        
        if (method == REQUEST_METHOD_GET && url.GetComponentSize() == 1)
            return SayHello(url[0]);
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
