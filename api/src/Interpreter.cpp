#include "Interpreter.h"
InterpreterBuilder::command_to_execute* InterpreterBuilder::command_to_execute::clone()
{
	return new command_to_execute(name, fn, outputMsg, context);
}

Interpreter::Interpreter()
	: m_isInitialized(false)
{}

void Interpreter::init()
{
	m_isInitialized = true;
}

void Interpreter::tick()
{
	if (!m_isInitialized)
		return;

	m_interpreterBuilder.executeAndPopCommand();
}

void Interpreter::shutdown()
{
	m_isInitialized = false;
}

void Interpreter::addCommand(const std::string& cmdName, std::string& outputMsg, void* context)
{
	m_interpreterBuilder.addCommand(cmdName, outputMsg, context);
}
