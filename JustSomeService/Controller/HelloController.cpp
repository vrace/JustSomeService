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
    std::vector<std::string> components = GetRequestPathComponents(request);
    
    if (method == REQUEST_METHOD_GET && components.empty())
        return SayHello();
    
    if (method == REQUEST_METHOD_GET && components.size() == 1)
        return SayHello(components[0]);
    
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
