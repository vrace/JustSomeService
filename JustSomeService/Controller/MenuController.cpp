#include "MenuController.h"
#include "../Base/HttpResponseEntity.h"

HttpResponse* MenuController::Dispatch(const HttpRequest &request)
{
    RequestMethod method = request.GetMethod();
    RequestURL url = request.GetURL("/menu");
    
    if (url)
    {
        if (method == REQUEST_METHOD_GET && url.GetComponentSize() == 0)
            return GetMenu();
        
        if (method == REQUEST_METHOD_GET && url.GetComponentSize() == 1 && url[0] == "random")
            return RandomFood();
    }
    
    return NULL;
}

HttpResponse* MenuController::GetMenu()
{
    std::vector<Food> menu = _service.GetMenu();
    JsonObject *data = _translator.Translate(menu);
    return new HttpResponseEntity<JsonObject>(HTTP_STATUS_OK, data);
}

HttpResponse* MenuController::RandomFood()
{
    Food food = _service.RandomFood();
    JsonObject *data = _translator.Translate(food);
    return new HttpResponseEntity<JsonObject>(HTTP_STATUS_OK, data);
}
