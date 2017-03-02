#include "action_set.h"

#include <stdio.h>

TINYREFL_CLASS_DEF(ActionSet)

int ActionSet::Handle()
{
    printf("ActionSet::Handle()\n");
    return 0;
}
