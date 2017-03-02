#include <stdio.h>

#include "action_base.h"
#include "action_set.h"

int main()
{
    ActionBase *handler = tinyrefl::MessageFactory("ActionGet");
    if (handler)
        handler->Handle();

    handler = tinyrefl::MessageFactory("ActionSet");
    if (handler)
        handler->Handle();

    return 0;
}

