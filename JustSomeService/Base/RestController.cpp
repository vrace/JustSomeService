#include "RestController.h"
#include <sstream>

RestController::RestController()
{
    
}

RestController::~RestController()
{
    
}

std::vector<std::string> RestController::GetRequestPathComponents(const HttpRequest &request)
{
    std::vector<std::string> components;
    
    const std::string &url = request.GetURL();
    const std::string &requestPath = GetRequestPath();
    
    if (url == requestPath || url.find(requestPath + '/') == 0)
    {
        std::stringstream ss(url.substr(requestPath.length()));
        
        std::string line;
        while (std::getline(ss, line, '/'))
        {
            if (!line.empty())
                components.push_back(line);
        }
    }
    
    return components;
}
