#include "HttpResponseTranslator.h"
#include "HttpHeader.h"
#include <sstream>

std::string HttpResponseTranslator::Translate(const HttpResponse &response)
{
    std::stringstream ss;
    
    ss << "HTTP/1.1 " << response.GetStatus() << "\r\n";
    
    const HttpHeader &header = response.GetHeader();
    for (HttpHeader::const_iterator it = header.begin(); it != header.end(); ++it)
        ss << it->first << ": " << it->second << "\r\n";
    
    ss << "\r\n";
    ss << response.GetPayload() << "\r\n";
    
    return ss.str();
}
