#include "Borrow.h"
#include "Client.h"
#include "Medias.h"

void BorrowList::BorrowMedia(const std::string& clientName, const std::string& mediaType, const std::string& title)
{
    Client* client = nullptr;
    bool found = false;
    for (auto i = m_clientlist.begin(); i != m_clientlist.end(); ++i)
    {
        client = *i;
        if (client->getName() == clientName)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << clientName << " introuvable " << std::endl;
        return;
    }

    IMedia* media = nullptr;
    for (auto i = m_medialist.begin(); i != m_medialist.end(); ++i)
    {
        media = *i;
        if (media->MediaType() == mediaType && media->title() == title)
        {
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << clientName << " introuvable " << std::endl;
        return;
    }

    BorrowList::borrow(client, media);
}


void BorrowList::borrow(Client* client, IMedia* media)
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

    if (media->getavailable() == false)
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
            std::cout << "tu es trop jeune!" << std::endl;
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
            std::cout << "tu es trop jeune!" << std::endl;
            return;
        }
    }
}

void BorrowList::available(IMedia* media)
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

void BorrowList::rentGiveBack(const std::string& mediaType, const std::string& title)
{
    IMedia* media;
    for (auto i = m_medialist.begin(); i != m_medialist.end(); ++i)
    {
        media = *i;
        if (media->MediaType() == mediaType
            && media->title() == title
            && media->getavailable())
        {
            giveBack(media);
        }
    }
}

void BorrowList::giveBack(IMedia* media)
{
    bool found = false;
    for (auto i = m_borrowlist.begin(); i != m_borrowlist.end(); ++i)
    {
        Borrow* borrowmedia;
        borrowmedia = *i;
        if (borrowmedia->getMedia() == media)
        {
            found = true;
            borrowmedia->getClient()->getSubBorrowcounter();
            std::cout << borrowmedia->getClient()->getFirstName() << " " << borrowmedia->getClient()->getName() << " a rendu le media" << std::endl;
            i = m_borrowlist.erase(i);
            delete borrowmedia;
            break;
        }
    }
    if (found)
    {
        media->setavailable(true);
        std::cout << media->title() << " " << media->MediaType() << " est disponible" << std::endl;
        media->infos();
    }
    else
        std::cout << "le media est indisponible" << std::endl;
}

void BorrowList::showBorrowMedia()
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

void BorrowList::showAvailableMedia()
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


void BorrowList::showWhoMedia(std::string& type, std::string& title)
{
    if (m_borrowlist.empty())
    {
        std::cout << "pas de medias emprunte" << std::endl;
    }

    bool found = false;
    for (auto i = m_borrowlist.begin(); i < m_borrowlist.end(); ++i)
    {
        for (auto i = m_borrowlist.begin(); i != m_borrowlist.end(); ++i)
        {
            Borrow* borrowmedia = *i;
            IMedia* media = borrowmedia->getMedia();

            if (media->MediaType() == type && media->title() == title)
            {
                found = true;
            }

            if (found)
            {
                std::cout << "Le media " << media->title() << " " << media->MediaType() << " est emprunte par "
                    << borrowmedia->getClient()->getFirstName() << " " << borrowmedia->getClient()->getName() << std::endl;
            }
            if (!found)
            {
                std::cout << "Le media " << title << type << " n'est pas emprunte" << std::endl;
            }
        }
    }

}

void BorrowList::showWhatMedia(const std::string& name, const std::string& fname, const std::string& mail)
{
    for (auto i = m_borrowlist.begin(); i < m_borrowlist.end(); ++i)
    {
        Borrow* borrowmedia = *i;
        std::cout << borrowmedia->getClient()->getFirstName() << " " << borrowmedia->getClient()->getName() << " a emprunte : " << std::endl;
        bool found = false;

        if (borrowmedia->getClient()->getFirstName() == fname
            && borrowmedia->getClient()->getName() == name)
        {
            found = true;
        }

        if (borrowmedia->getClient()->getFirstName() == fname
            && borrowmedia->getClient()->getName() == name
            && borrowmedia->getClient()->getMail() == mail)
        {
            found = true;
        }

        if (borrowmedia->getClient()->getMail() == mail)
        {
            found = true;
        }

        if (found)
        {

            std::cout << " - " << borrowmedia->getMedia()->title()
                << " (" << borrowmedia->getMedia()->MediaType() << ") " << std::endl;

        }
        if (!found)
        {
            std::cout << " rien " << std::endl;
        }
    }
    
}



 
