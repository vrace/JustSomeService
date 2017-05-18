#ifndef MENU_SERVICE_H
#define MENU_SERVICE_H

#include "../Model/Food.h"
#include <vector>

class MenuService
{
public:
    std::vector<Food> GetMenu();
    Food RandomFood();
    
private:
    Food MakeFood(const std::string &name);
};

#endif
