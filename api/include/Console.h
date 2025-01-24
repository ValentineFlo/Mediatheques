#pragma once
#include <vector>
#include <iostream>
#include "windows.h"

namespace Mediatheque
{

    class Console
    {
    private:
        static std::vector<std::string> screenBuffer;

    public:

        static std::string read()
        {
            std::string input;

            HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
            char buffer[1024];
            DWORD charsRead;
            ReadConsoleA(hConsole, buffer, sizeof(buffer), &charsRead, nullptr);
            if (charsRead > 0)
            {
                if (buffer[charsRead - 1] == '\n') charsRead--;
                if (buffer[charsRead - 1] == '\r') charsRead--;
                input.assign(buffer, charsRead);
            }
            return input; 
        }

    };

    std::vector<std::string> Console::screenBuffer;
}

