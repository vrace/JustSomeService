#ifndef MENU_TRANSLATOR_H
#define MENU_TRANSLATOR_H

#include "../Model/Food.h"
#include "../SimpleJson/JsonObject.h"
#include <vector>

class MenuTranslator
{
public:
    JsonObject* Translate(const Food &food);
    JsonObject* Translate(const std::vector<Food> &menu);
};

#endif
