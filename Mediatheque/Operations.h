#pragma once
class Borrow
{
public:
    Borrow(Client* client, IMedia* media) : m_clientborrower(client), m_mediaborrow(media)
    {
        std::cout << client->getFirstName() << " " << client->getName()
            << " a emprunte : " << media->title() << std::endl;
    }

    IMedia* getMedia() const { return m_mediaborrow; }
    Client* getClient() const { return m_clientborrower; }

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