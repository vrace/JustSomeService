#include "Food.h"

bool Food::IsValid() const
{
    return !_name.empty();
}

void Food::SetName(const std::string &name)
{
    _name = name;
}

const std::string& Food::GetName() const
{
    return _name;
}
