#pragma once
// Mediatheque.cpp : Ce fichier contient la fonction 'main'. L'ex�cution du programme commence et se termine � cet endroit.
//
#include "Medias.h"
#include "Client.h"
#include "Operations.h"

class Mediatheque
{
public:
    ~Mediatheque()
    {}

    void addClient(Client* client)
    {
        m_clientlist.push_back(client);
        return;

    }

    void addMedia(IMedia* media)
    {
        m_medialist.push_back(media);
        return;
    }

    void showClient()
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

    void showMedia()
    {
        IMedia* media;
        std::cout << std::endl;
        std::cout << "Liste des medias avec leurs Infos : " << std::endl;


        if (m_medialist.empty())
        {
            std::cout << "Il n' y a pas de medias!" << std::endl;
            std::cout << std::endl;
        }

        for (auto i = m_medialist.begin(); i != m_medialist.end(); ++i)
        {
            media = *i;

            if (media != nullptr)
            {
                std::cout << std::endl;
                std::cout << "Type de medias : " << media->MediaType() << std::endl;
                std::cout << "Titre : " << media->title() << std::endl;
                media->infos();
                showStateMedia(media);
            }
        }

    }

    void showStateMedia(IMedia* media)
    {
        if (!media->getavailable())
        {
            std::cout << "Type : " << media->MediaType() << std::endl;
            std::cout << "Titre : " << media->title() << std::endl;
            std::cout << "State : borrow" << std::endl;
        }
        else
        {
            std::cout << "Type : " << media->MediaType() << std::endl;
            std::cout << "Titre : " << media->title() << std::endl;
            std::cout << "State : available" << std::endl;
        }
        std::cout << std::endl;
    }

    void removeClient(const std::string& name, const std::string& fname, const std::string& mail)
    {

        auto i = m_clientlist.begin();
        while (i != m_clientlist.end())
        {
            Client* clientdelete = *i;
            if ((clientdelete->getName() == name
                && clientdelete->getFirstName() == fname)
                || clientdelete->getMail() == mail)
            {
                std::cout << clientdelete->getFirstName() << " "
                    << clientdelete->getName() << " "
                    << clientdelete->getMail() << " a etait supprime" << std::endl;
                std::cout << std::endl;
                delete clientdelete;
                i = m_clientlist.erase(i);
            }

            else
            {
                ++i;
            }

        }
    }


    void removeMedia(const std::string& type, const std::string& title)
    {
        bool found = false;
        if (m_medialist.empty())
        {
            std::cout << "Inventaire vide" << std::endl;
            return;
        }

        auto i = m_medialist.begin();
        while (i != m_medialist.end())
        {
            IMedia* mediadelete = *i;
            if (mediadelete->MediaType() == type && mediadelete->title() == title && mediadelete->getavailable())
            {
                found = true;
                std::cout << mediadelete->MediaType() << " "
                    << mediadelete->title() << " a etait supprime" << std::endl;
                std::cout << std::endl;
                delete mediadelete;
                i = m_medialist.erase(i);
            }
            else if (mediadelete->MediaType() == type && mediadelete->title() == title && !mediadelete->getavailable())
            {
                std::cout << "Medias empunte et ne peut pas etre supprime";
                std::cout << std::endl;
            }

            else
            {
                ++i;
            }

        }
        if (!found)
        {
            std::cout << "le medias a suprimer est introuvable" << std::endl;
            std::cout << std::endl;
        }
        
    }


    void borrow(Client* client, IMedia* media)
    {
        auto i = std::find(m_clientlist.begin(), m_clientlist.end(), client);
        if (i == m_clientlist.end())
        {
            std::cout << "Client introuvable" << std::endl;
            return;
        }

        if (client->getBorrowcounter() > 5)
        {
            std::cout << client->getFirstName() << " " << client->getName() << " a trop de medias" << std::endl;
            return;
        }

        if (!media->getavailable())
        {
            std::cout << "Medias deja emprunte" << std::endl;
            return;
        }

        if (Book* book = dynamic_cast<Book*> (media))
        {
            Borrow* borrow = new Borrow(client, media);
            media->setavailable(false);
            m_borrowlist.push_back(borrow);
            client->getAddBorrowcounter();
            return;
        }

        if (Movie* movie = dynamic_cast<Movie*> (media))
        {
            if (movie->getOldlimit() < client->getOld())
            {
                Borrow* borrow = new Borrow(client, media);
                media->setavailable(false);
                m_borrowlist.push_back(borrow);
                client->getAddBorrowcounter();
                return;
            }
            else if (movie->getOldlimit() > client->getOld())
            {
                std::cout << "tu es trop jeune" << std::endl;
                return;
            }
        }
        if (VideoGame* videogame = dynamic_cast<VideoGame*> (media))
        {
            if (videogame->getPegi() < client->getOld())
            {
                Borrow* borrow = new Borrow(client, media);
                media->setavailable(false);
                m_borrowlist.push_back(borrow);
                client->getAddBorrowcounter();
                return;
            }
            else if (videogame->getPegi() > client->getOld())
            {
                std::cout << "tu es trop jeune" << std::endl;
                return;
            }
        }
    }

    void available(IMedia* media)
    {
        if (media->getavailable())
        {
            std::cout << "Le media est deja disponible : " << media->title() << std::endl;
        }
        else
        {
            media->setavailable(true);
            std::cout << "Le media est disponible : " << media->title() << std::endl;
        }
    }



    void giveBack(Client* client, IMedia* media)
    {
        
        for (auto i = m_borrowlist.begin(); i < m_borrowlist.end(); ++i)
        {
            Borrow* borrow = *i;
            if (borrow->getMedia()->title() == media->title())
            {
                media->setavailable(true);
                std::cout << client->getFirstName() << " " << client->getName()
                    << " a rendu " << media->title() << " " << media->MediaType() << std::endl;
                media->infos();
                i = m_borrowlist.erase(i);
                client->getSubBorrowcounter();

            }
        }
        
    }

    void showBorrowMedia()
    {
        Borrow* borrowMedia;
        std::cout << std::endl;
        std::cout << "Liste des medias empruntes avec leurs Infos : " << std::endl;

        if (m_borrowlist.empty())
        {
            std::cout << "Il n' y a pas de medias empruntes!" << std::endl;
        }

        else
        {
            for (auto i = m_borrowlist.begin(); i != m_borrowlist.end(); ++i)
            {
                borrowMedia = *i;

                std::cout << "Type : " << borrowMedia->getMedia()->MediaType() << std::endl;
                std::cout << "Title : " << borrowMedia->getMedia()->title() << std::endl;
                borrowMedia->getMedia()->infos();
                std::cout << std::endl;

            }
        }
    }

    void showAvailableMedia()
    {
        std::cout << "Liste des medias disponibles et leurs infos : " << std::endl;

        bool found = false;
        for (auto i = m_medialist.begin(); i < m_medialist.end(); ++i)
        {
            IMedia* media = *i;
            if (media->getavailable())
            {
                found = true;
                std::cout << "Type : " << media->MediaType() << std::endl; 
                std::cout << "Titre : " << media->title() << std::endl; 
                media->infos();
                std::cout << std::endl;
            }
        }

        if (!found)
        {
            std::cout << "Medias inexistant" << std::endl;
        }
    }

    void ShowWhoMedia(IMedia* media)
    {
        
        if (media->getavailable())
        {
            std::cout << "Ce media est disponible" << std::endl;
            return;
        }


        for (auto i = m_borrowlist.begin(); i < m_borrowlist.end(); ++i)
        {
            Borrow* borrowmedia = *i;
            if (borrowmedia->getMedia()->MediaType() == media->MediaType()
                && borrowmedia->getMedia()->title() == media->title())
            {
                std::cout <<"Le media : " << media->title() << " " << media->MediaType()<<" est emprunte par "
                << borrowmedia->getClient()->getFirstName() << " " << borrowmedia->getClient()->getName() << std::endl;
            }
        }

    }

    void ShowWhatMedia(Client* client)
    {
       std::cout << client->getFirstName() << " " << client->getName() << " a emprunte : " << std::endl;

        for (auto i = m_borrowlist.begin(); i < m_borrowlist.end(); ++i)
        {
            Borrow* borrowmedia = *i;
            if (borrowmedia->getClient()->getFirstName() == client->getFirstName()
                && borrowmedia->getClient()->getName() == client->getName())
            {
                std::cout << " - " << borrowmedia->getMedia()->title()
                    << " (" << borrowmedia->getMedia()->MediaType() << ") " << std::endl;

            }
        }
    }


private:
    std::vector<Client*> m_clientlist;
    std::vector<IMedia*> m_medialist;
    std::vector<Borrow*> m_borrowlist;
};


