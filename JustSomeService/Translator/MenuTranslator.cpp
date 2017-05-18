#include "MenuTranslator.h"
#include "../SimpleJson/JsonArray.h"

JsonObject* MenuTranslator::Translate(const Food &food)
{
    JsonObject *data = new JsonObject();
    data->Put("name", food.GetName());
    return data;
}

JsonObject* MenuTranslator::Translate(const std::vector<Food> &menu)
{
    JsonObject *data = new JsonObject();
    JsonArray *arr = new JsonArray();
    data->Put("menu", arr);
    
    for (std::vector<Food>::const_iterator it = menu.begin(); it != menu.end(); ++it)
        arr->push_back(Translate(*it));
    
    return data;
}
