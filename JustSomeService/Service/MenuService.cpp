#include "MenuService.h"
#include <stdlib.h>

std::vector<Food> MenuService::GetMenu()
{
    std::vector<Food> menu;
    
    menu.push_back(MakeFood("麦当劳鸡排饭"));
    menu.push_back(MakeFood("银泰城冒菜"));
    menu.push_back(MakeFood("冒菜（美年）"));
    menu.push_back(MakeFood("兰州拉面"));
    menu.push_back(MakeFood("兵哥碗杂"));
    menu.push_back(MakeFood("宜宾燃面"));
    menu.push_back(MakeFood("米粉"));
    menu.push_back(MakeFood("炒饭"));
    menu.push_back(MakeFood("鳝鱼面"));
    
    return menu;
}

Food MenuService::RandomFood()
{
    std::vector<Food> menu = GetMenu();
    
    if (!menu.empty())
        return menu[rand() % menu.size()];
    
    return MakeFood("No food for you!");
}

Food MenuService::MakeFood(const std::string &name)
{
    Food food;
    food.SetName(name);
    return food;
}
