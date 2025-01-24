#ifndef API_H
#define API_H
#include "Interpreter.h"

Interpreter& getInterpreter();

void cmd_init();
void cmd_tick();
void cmd_shutdown();

#endif // API_H
