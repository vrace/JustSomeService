#include <iostream>
#include "Base/HttpRequestTranslator.h"
#include "Base/HttpResponseTranslator.h"

static const char TEST_MESSAGE[] =
"GET /hello HTTP/1.1\r\n"
"Host: localhost:12707\r\n"
"Upgrade-Insecure-Requests: 1\r\n"
"Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\r\n"
"User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_3) AppleWebKit/602.4.8 (KHTML, like Gecko) Version/10.0.3 Safari/602.4.8\r\n"
"Accept-Language: en-us\r\n"
"Accept-Encoding: gzip, deflate\r\n"
"Connection: keep-alive\r\n"
"\r\n"
"I am payload\r\n";

int main()
{
    HttpRequestTranslator requestTranslator;
    HttpResponseTranslator responseTranslator;
    
    HttpRequest *request = requestTranslator.Translate(TEST_MESSAGE);
    
    HttpResponse response(HttpStatus(HTTP_STATUS_OK), request->GetHeader(), "I'm the payload!");
    std::string res = responseTranslator.Translate(response);
    std::cout << res << std::endl;
    
    delete request;
    
    return 0;
}
