#include "Client.h"


ClientList::~ClientList()
{
    for (auto it = m_clientlist.begin(); it != m_clientlist.end(); ++it) {
        delete* it;
    }
    m_clientlist.clear();
}

void ClientList::addClient(Client* client)
{
    std::cout << client->getFirstName() << " "
        << client->getName() << " "
        << client->getMail() << " a etait ajoute" << std::endl;
    std::cout << std::endl;
    m_clientlist.push_back(client);
    return;
}

void ClientList::showClient()
{
    Client* client;
    std::cout << std::endl;
    std::cout << "Liste des clients avec leurs Infos : " << std::endl;

    if (m_clientlist.empty())
    {
        std::cout << "Il n y a pas de client!" << std::endl;
    }


    for (auto i = m_clientlist.begin(); i != m_clientlist.end(); ++i)
    {
        client = *i;

        if (client != nullptr)
        {
            std::cout << std::endl;
            std::cout << "FirstName : " << client->getFirstName() << std::endl;
            std::cout << "Name : " << client->getName() << std::endl;
            std::cout << "Old : " << client->getOld() << std::endl;
            std::cout << "Adress : " << client->getAdress() << std::endl;
            std::cout << "Phone : " << client->getPhone() << std::endl;
            std::cout << "Mail : " << client->getMail() << std::endl;
        }
    }
}
void ClientList::removeClient(const std::string& name, const std::string& fname, const std::string& mail)
{

    for (auto i = m_clientlist.begin();i != m_clientlist.end();++i)
    {
        Client* clientdelete = *i;
        if (clientdelete->getBorrowcounter() != 0)
        {
            std::cout << clientdelete->getFirstName() << " "
                << clientdelete->getName() << " "
                << " pouvez vous rendre le media avant de partir ? " << std::endl;
            return;
        }


        if ((clientdelete->getName() == name && fname.empty() && mail.empty())
            || (name.empty() && fname.empty() && clientdelete->getMail() == mail)
            || (clientdelete->getName() == name && clientdelete->getFirstName() == fname && mail.empty())
            || (clientdelete->getName() == name && clientdelete->getFirstName() == fname && clientdelete->getMail() == mail))
        {
            std::cout << clientdelete->getFirstName() << " "
                << clientdelete->getName() << " "
                << clientdelete->getMail() << " a etait supprime" << std::endl;
            std::cout << std::endl;
            delete clientdelete;
            i = m_clientlist.erase(i);
            break;
        }



    }

}