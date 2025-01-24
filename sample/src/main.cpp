#include <iostream>
#include "Api.h"
#include "process.h"


int main()
{
	    Process proces;

    std::vector<std::string> instructionList =
    {
         "addClient Jean Dupont 25 rue 123456789 jean@email.com"
        ,"addClient charlotte Dupont 25 rue 123456789 jean@email.com"
        ,"addMedia Book dfdfi 265"
        ,"addMedia Movie jdjif dfdfi 18"
        ,"rent Dupont Book dfdfi"
        ,"stateMedia Book dfdfi"
        ,"listMedia"
        ,"listClient"
        ,"removeClient jean@email.com"
        ,"who Book dfdfi"
        ,"who Movie jdjif"
        ,"returnMedia Book dfdfi"
        ,"who Book dfdfi"
        ,"showMedia Jean Dupont"
    };



    while (!instructionList.empty())
    {
        std::string instruction = instructionList.front();
        instructionList.erase(instructionList.begin());


        try
        {
           proces.process(instruction);
        }
        catch (std::runtime_error& e)
        {
            std::cerr << e.what();
        }

        ::getchar();
    }

    return 0;
	std::string msg;
	void* data = new std::string("hello");

	getInterpreter().addCommand("echo", msg, data);
	msg += "toto";
	getInterpreter().addCommand("echo", msg, data);

	cmd_init();
	cmd_tick();
	std::cout << msg << std::endl;
	cmd_tick();
	std::cout << msg << std::endl;
	

	cmd_shutdown();
	
	return 0;
}