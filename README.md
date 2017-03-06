# tinyrefl
reflection in C++
## Usage
**class header file:**

	#include "tinyrefl.h"

	#pragma once

	TINYREFL_CLASS_DEC_BEGIN(ActionBase)
	public:
		virtual int Handle();
	TINYREFL_CLASS_DEC_END(ActionBase)

	DESCRIPTOR_DB_DEC(ActionBase)
	
**class source file:**	

	#include "action_base.h"

	DESCRIPTOR_DB_DEF(ActionBase)

	TINYREFL_CLASS_DEF(ActionBase)

	int ActionBase::Handle()
	{
		return 0;
	}
	
**main file:**	
	
	#include <stdio.h>

	#include "action_base.h"

	int main()
	{
		ActionBase *handler = tinyrefl::MessageFactory("ActionBase");
		if (handler)
		{
			handler->Handle();
			delete handler;
		}

		return 0;
	}
