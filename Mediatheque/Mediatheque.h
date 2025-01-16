#pragma once
// Mediatheque.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include <iostream>
#include <vector>


class IMedia
{
public:

    IMedia() {}
    virtual ~IMedia() = default;
    virtual std::string MediaType() const = 0;
    virtual std::string title() const = 0;
    virtual bool available() { return isAvailable; }


protected:
    bool isAvailable{ true };
};


class Book : public IMedia
{
public:

    Book(std::string title, int isbn)
        : m_title(title)
        , m_ISBN(isbn)
    {
    }

    virtual std::string MediaType() const override { return "Book"; }
    virtual std::string title() const override { return m_title; }
    int ibn() const { return m_ISBN; }

    void addBookToBookList(Book* book)
    {
        m_booklist.push_back(book);
        return;
    }


private:
    int m_ISBN;
    std::string m_title;
    std::vector<Book*> m_booklist;
};

class Movie : public IMedia
{
public:

    Movie(std::string title, std::string support, int ageLimit)
        : m_support(support)
        , m_ageLimit(ageLimit)
        , m_title(title)
    {
    }

    virtual std::string MediaType() const override { return "Movie"; }
    virtual std::string title() const override { return m_title; }

    void addMovieToMovieList(Movie* movie)
    {
        m_movielist.push_back(movie);
        return;
    }


private:
    std::string m_title;
    std::string m_support;
    int m_ageLimit;
    std::vector<Movie*> m_movielist;
};

class VideoGame : public IMedia
{
public:

    VideoGame(std::string title, std::string studio, int pegi, std::string genre)
        : m_title(title)
        , m_studio(studio)
        , m_pegi(pegi)
        , m_genre(genre)
    {
    }


    virtual std::string MediaType() const override { return "Video Game"; }
    virtual std::string title() const override { return m_title; }

    void addVideoGameToVideoGameList(VideoGame* videogame)
    {
        m_VideoGamelist.push_back(videogame);
        return;
    }



private:
    std::string m_title;
    std::string m_studio;
    int m_pegi;
    std::string m_genre;
    std::vector<VideoGame*> m_VideoGamelist;
};


class Client
{
public:
    Client(const std::string NAME, std::string FNAME, int OLD, std::string ADRESS, int PHONE, std::string MAIL)
        : m_name(NAME)
        , m_firstname(FNAME)
        , m_old(OLD)
        , m_adress(ADRESS)
        , m_phoneNumber(PHONE)
        , m_mail(MAIL)
    {
    }

    void setName(const std::string& name) { m_name = name; }
    void setFirstName(const std::string& fname) { m_firstname = fname; }
    void setOld(int old) { m_old = old; }
    void setAdress(const std::string& adress) { m_adress = adress; }
    void setPhone(int phone) { m_phoneNumber = phone; }
    void setMail(const std::string& mail) { m_mail = mail; }

    std::string getName() const { return m_name; }
    std::string getFirstName() const { return m_firstname; }
    int getOld() const { return m_old; }
    std::string getAdress() const { return m_adress; }
    int getPhone() const { return m_phoneNumber; }
    std::string getMail() const { return m_mail; }

private:
    std::string m_name;
    std::string m_firstname;
    int m_old;
    std::string m_adress;
    int m_phoneNumber;
    std::string m_mail;
};

class Mediatheque
{
public:
    ~Mediatheque() {}

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
            std::cout << "Il n' y a pas de client!" << std::endl;
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
        }

        for (auto i = m_medialist.begin(); i != m_medialist.end(); ++i)
        {
            media = *i;

            if (media != nullptr)
            {
                std::cout << std::endl;
                std::cout << "Type de medias : " << media->MediaType() << std::endl;
                std::cout << "Titre : " << media->title() << std::endl;
                std::cout << "Accessibilite : " << media->available() << std::endl;
            }
        }

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
        auto i = m_medialist.begin();
        while (i != m_medialist.end())
        {
            IMedia* mediadelete = *i;
            if (mediadelete->MediaType() == type && mediadelete->title() == title)
            {
                std::cout << mediadelete->MediaType() << " "
                    << mediadelete->title() << " a etait supprime" << std::endl;
                delete mediadelete;
                i = m_medialist.erase(i);
            }

            else
            {
                ++i;
            }

        }
    }

private:
    std::vector<Client*> m_clientlist;
    std::vector<IMedia*> m_medialist;
};



