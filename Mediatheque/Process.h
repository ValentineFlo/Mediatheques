#pragma once

#include <iostream>
#include "Borrow.h"
#include "Exceptions.h" 
#include "InputCommand.h"


class Process : public BorrowList
{
public:
    void process(const std::string& instruction)
    {
        std::vector<std::string> tokenList = splitIntoTokens(instruction);
        const std::string& instructionType = tokenList[0];

        if (instructionType == "addClient")
        {
            if (tokenList.size() != 7)
                throw InvalidNumberOfOperandInstruction();

            std::string fname(tokenList[1]);
            std::string name(tokenList[2]);
            int old = std::stoi(tokenList[3]);
            std::string adress(tokenList[4]);
            int phone = std::stoi(tokenList[5]);
            std::string mail(tokenList[6]);

            Client* client = new Client{ name, fname, old, adress, phone, mail };
            addClient(client);

        }
        if (instructionType == "addMedia")
        {
            const std::string& mediaType = tokenList[1];
            if (mediaType == "Book")
            {
                if (tokenList.size() != 4)
                    throw InvalidNumberOfOperandInstruction();

                std::string title(tokenList[2]);
                int isbn = std::stoi(tokenList[3]);

                Book* book = new Book{ title, isbn };
                addMedia(book); 
            }

            else if (mediaType == "Movie")
            {
                if (tokenList.size() != 5)
                    throw InvalidNumberOfOperandInstruction();

                std::string title(tokenList[2]);
                std::string support(tokenList[3]);
                int old = std::stoi(tokenList[4]);

                Movie* movie = new Movie{ title, support, old };
                addMedia(movie);
            }

            else if (mediaType == "VideoGame")
            {
                if (tokenList.size() != 6)
                    throw InvalidNumberOfOperandInstruction();

                std::string title(tokenList[2]);
                std::string studio(tokenList[3]);
                int pegi = std::stoi(tokenList[4]);
                std::string genre(tokenList[5]);

                VideoGame* videogame = new VideoGame{ title, studio, pegi, genre };
                addMedia(videogame);
            }
        }

        if (instructionType == "removeClient")
        {
            if (tokenList.size() > 4 || tokenList.size() < 2)
                throw InvalidNumberOfOperandInstruction();

            if (tokenList.size() == 2)
            {
                std::string secondToken = tokenList[1];
                if (secondToken.find('@') != std::string::npos)
                {
                    removeClient("", "", secondToken);
                }
                else
                    removeClient(secondToken, "", "");
            }


            if (tokenList.size() == 3)
            {
                std::string fname(tokenList[1]);
                std::string name(tokenList[2]);
                removeClient(name, fname, "");
            }

            if (tokenList.size() == 4)
            {
                std::string name(tokenList[1]);
                std::string fname(tokenList[2]);
                std::string mail(tokenList[3]);
                removeClient(name, fname, mail);
            }

        }

        if (instructionType == "removeMedia")
        {
            if (tokenList.size() != 3)
                throw InvalidNumberOfOperandInstruction();

            std::string mediaType(tokenList[1]);
            std::string title(tokenList[2]);

            removeMedia(mediaType, title);

        }


        if (instructionType == "listClient")
        {
            if (tokenList.size() != 1)
                throw InvalidNumberOfOperandInstruction();

            showClient();
        }

        if (instructionType == "listMedia")
        {
            if (tokenList.size() != 1)
                throw InvalidNumberOfOperandInstruction();

            showMedia();
        }

        if (instructionType == "stateMedia")
        {
            if (tokenList.size() != 3)
                throw InvalidNumberOfOperandInstruction();

            std::string mediaType(tokenList[1]);
            std::string title(tokenList[2]);
            showState(mediaType, title);
        }

        if (instructionType == "who")
        {
            if (tokenList.size() != 3)
                throw InvalidNumberOfOperandInstruction();

            std::string mediaType(tokenList[1]);
            std::string title(tokenList[2]);
            showWhoMedia(mediaType, title);
        }

        if (instructionType == "rent")
        {
            if (tokenList.size() != 4)
                throw InvalidNumberOfOperandInstruction();

            std::string clientName(tokenList[1]);
            std::string mediaType(tokenList[2]);
            std::string title(tokenList[3]);
            BorrowMedia(clientName, mediaType, title);
        }

        if (instructionType == "returnMedia")
        {
            if (tokenList.size() != 3)
                throw InvalidNumberOfOperandInstruction();

            std::string mediaType(tokenList[1]);
            std::string title(tokenList[2]);
           rentGiveBack(mediaType, title);
        }

        if (instructionType == "showMedia")
        {
            if (tokenList.size() > 4 || tokenList.size() < 2)
                throw InvalidNumberOfOperandInstruction();

            if (tokenList.size() == 2)
            {
                std::string secondToken = tokenList[1];
                if (secondToken.find('@') != std::string::npos)
                {
                    showWhatMedia("", "", secondToken);
                }
                else
                    showWhatMedia(secondToken, "", "");
            }


            if (tokenList.size() == 3)
            {
                std::string fname(tokenList[1]);
                std::string name(tokenList[2]);
                showWhatMedia(name, fname, "");
            }

            if (tokenList.size() == 4)
            {
                std::string name(tokenList[1]);
                std::string fname(tokenList[2]);
                std::string mail(tokenList[3]);
                showWhatMedia(name, fname, mail);
            }

        }


    }
    
};
    

