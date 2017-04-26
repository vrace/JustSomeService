#include "RollService.h"
#include <stdlib.h>
#include <time.h>

RollService::RollService()
{
    srand((unsigned int)time(NULL));
}

int RollService::Roll()
{
    return 1 + rand() % 100;
}

int RollService::Roll(int maxval)
{
    return 1 + rand() % maxval;
}
