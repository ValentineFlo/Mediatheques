#include "Medias.h"

MediaList::~MediaList()
{
    for (auto it = m_medialist.begin(); it != m_medialist.end(); ++it) {
        delete* it;
    }
    m_medialist.clear();
}

void MediaList::addMedia(IMedia* media)
{
    std::cout << media->MediaType() << " "
        << media->title() << " a etait ajoute" << std::endl;
    std::cout << std::endl;
    m_medialist.push_back(media);
    return;
}


void MediaList::showMedia()
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

void MediaList::removeMedia(const std::string& type, const std::string& title)
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


void MediaList::showState(const std::string& type, const std::string& title)
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
        IMedia* media = *i;
        if (media->MediaType() == type && media->title() == title)
        {
            found = true;
            showStateMedia(media);
            break;
        }

        else
        {
            ++i;
        }

    }
    if (!found)
    {
        std::cout << "le medias est introuvable" << std::endl;
        std::cout << std::endl;
        return;
    }

}

void MediaList::showStateMedia(IMedia* media)
{
    if (media != nullptr)
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

}