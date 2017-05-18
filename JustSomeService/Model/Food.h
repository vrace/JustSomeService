#ifndef FOOD_H
#define FOOD_H

#include <string>

class Food
{
public:
    bool IsValid() const;
    
    void SetName(const std::string &name);
    const std::string& GetName() const;
    
private:
    std::string _name;
};

#endif
