#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "../Base/RestController.h"
#include "../Service/MenuService.h"
#include "../Translator/MenuTranslator.h"

class MenuController : public RestController
{
public:
    HttpResponse* Dispatch(const HttpRequest &request);
    
private:
    HttpResponse* GetMenu();
    HttpResponse* RandomFood();
    
private:
    MenuService _service;
    MenuTranslator _translator;
};

#endif
