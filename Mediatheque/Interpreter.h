#ifndef INTERPRETER_H
#define INTERPRETER_H
#include <functional>
#include <map>
#include <string>
#include <queue>
#include <stdexcept>

#include "Command.h"

class InterpreterBuilder
{
public:
	using fn_type = std::function<void(std::string&, void*)>;
	InterpreterBuilder()
	{
		m_factory.registerType(EchoCommand::name, new EchoCommand);
	}

	void addCommand(const std::string& name, std::string& outputMsg, void* context)
	{
		auto* command = m_factory.create(name, outputMsg, context);
		m_commandQueue.push(command);
	}

	void executeAndPopCommand()
	{
		auto* command = m_commandQueue.front();
		command->apply();
		delete command;
		command = nullptr;
		m_commandQueue.pop();
	}

private:
	struct command_to_execute
	{
		command_to_execute(const std::string& name_, const fn_type& fn_, std::string& outputMsg_, void* context_)
			: name(name_)
			, fn(fn_)
			, outputMsg(outputMsg_)
			, context(context_)
		{
		}

		command_to_execute* clone();

		std::string name;
		fn_type fn;
		std::string& outputMsg;
		void* context;
	};

	class Factory
	{
	public:
		void registerType(const std::string& key, ICommand* command)
		{
			if (m_registry.contains(key))
				throw std::runtime_error("Key is already registered");

			m_registry.insert({ key, command });
		}

		ICommand* create(const std::string& key, std::string& output, void* context)
		{
			if (auto it = m_registry.find(key); it == m_registry.end())
				throw std::runtime_error("Key is not registered");
			else
				return it->second->clone(output, context);
		}

		~Factory()
		{
			for (auto& [key, value] : m_registry)
			{
				delete value;
				value = nullptr;
			}

			m_registry.clear();
		}

	private:
		std::map<std::string, ICommand*> m_registry;
	};

	Factory m_factory;
	std::queue<ICommand*> m_commandQueue;
};

class Interpreter
{
public:
	using fn_type = std::function<void(std::string&, void*)>;
	Interpreter();

	void init();
	void tick();
	void shutdown();
	void addCommand(const std::string& cmdName, std::string& outputMsg, void* context);

private:
	bool m_isInitialized;
	InterpreterBuilder m_interpreterBuilder;
};

#endif // INTERPRETER_H
