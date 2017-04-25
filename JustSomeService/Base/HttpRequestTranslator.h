#ifndef HTTP_REQUEST_TRANSLATOR_H
#define HTTP_REQUEST_TRANSLATOR_H

#include "HttpRequest.h"

class HttpRequestTranslator
{
public:
    HttpRequest* Translate(const std::string &request);
};

#endif
