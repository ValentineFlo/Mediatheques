#pragma once
#include "Client.h"
#include "Medias.h"

class Borrow
{
public:
    Borrow(Client* client, IMedia* media) : m_clientborrower(client), m_mediaborrow(media)
    {
        std::cout << client->getFirstName() << " " << client->getName()
            << " a emprunte : " << media->title() << std::endl;
    }

    IMedia* getMedia() const
    {
        return m_mediaborrow;
    }
    Client* getClient() const
    {
        return m_clientborrower;
    }


private:
    Client* m_clientborrower;
    IMedia* m_mediaborrow;
};

class Available
{
public:
    Available(IMedia* media) : m_mediaAvailable(media)
    {
        std::cout << "Medias disponible : " << media->title() << " " << media->MediaType() << std::endl;
        media->infos();
    }

    IMedia* getMedia() const { return m_mediaAvailable; }

private:
    IMedia* m_mediaAvailable;
};

class BorrowList : public ClientList
{
public:
    void BorrowMedia(const std::string& clientName, const std::string& mediaType, const std::string& title);
    void borrow(Client* client, IMedia* media);
    void available(IMedia* media);
    void rentGiveBack(const std::string& mediaType, const std::string& title);
    void giveBack(IMedia* media);
    void showBorrowMedia();
    void showAvailableMedia();
    void showWhoMedia(std::string& type, std::string& title);
    void showWhatMedia(const std::string& name, const std::string& fname, const std::string& mail);

    std::vector<Borrow*> m_borrowlist;

};