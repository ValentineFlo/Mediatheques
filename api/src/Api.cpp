#include "Api.h"

Interpreter& getInterpreter()
{
	static Interpreter interpreter;
	return interpreter;
}

void cmd_init()
{
	getInterpreter().init();
}

void cmd_tick()
{
	getInterpreter().tick();
}

void cmd_shutdown()
{
	getInterpreter().shutdown();
}
