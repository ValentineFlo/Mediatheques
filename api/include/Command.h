#ifndef COMMAND_H
#define COMMAND_H
#include <string>

struct ICommand
{
	virtual ~ICommand() = default;
	virtual ICommand* clone(std::string& outputMsg, void* context) = 0;
	virtual void apply() = 0;
};

struct EchoCommand : public ICommand
{
	static const std::string name;
	EchoCommand()
		: m_outputMsg(nullptr)
		, m_context(nullptr)
	{}

	EchoCommand(std::string& outputMsg, void* context)
		: m_outputMsg(&outputMsg)
		, m_context(context)
	{
	}

	ICommand* clone(std::string& outputMsg, void* context) override
	{
		return new EchoCommand(outputMsg, context);
	}

	void apply() override
	{
		*m_outputMsg += *static_cast<std::string*>(m_context);
	}

private:
	std::string* m_outputMsg;
	void* m_context;
};




#endif // COMMAND_H
