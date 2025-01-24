#include <iostream>
#include "Process.h"
#include "Console.h"


int main()
{
    
    Process process;
    std::cout << "Bienvenue dans la mediatheque!" << std::endl;
    std::cout << "exit pour quitter" << std::endl;
    std::cout << "--help pour l'aide" << std::endl;

    while (true)
    {

        std::string commandline = Mediatheque::Console::read();

        if (commandline == "exit")
        {
            break;
        }

        if (!commandline.empty())
        {
            try
            {
                process.process(commandline);
            }
            catch (const std::runtime_error& e)
            {
                std::cout << "Erreur: " + std::string(e.what()) << std::endl;
            }
        }

    }
}