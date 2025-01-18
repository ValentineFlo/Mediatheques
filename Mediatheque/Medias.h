#pragma once
#include <iostream>
#include <vector>

class IMedia
{
public:

    IMedia() {}
    virtual ~IMedia() = default;
    virtual std::string MediaType() const = 0;
    virtual std::string title() const = 0;
    virtual void infos() const = 0;
    virtual bool getavailable() { return isAvailable; }
    virtual void setavailable(bool available) { isAvailable = available; }


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
    virtual void infos() const override
    {
        std::cout << "L'isbn est " << m_ISBN << std::endl;
    }



private:
    int m_ISBN;
    std::string m_title;
};

class Movie : public IMedia
{
public:

    Movie(std::string title, std::string support, int ageLimit)
        : m_support(support)
        , m_oldlimit(ageLimit)
        , m_title(title)
    {
    }

    virtual std::string MediaType() const override { return "Movie"; }
    virtual std::string title() const override { return m_title; }
    virtual void infos() const override
    {
        std::cout << "Le support est : " << m_support << std::endl;
        std::cout << "La limite de l age est de : " << m_oldlimit << " ans" << std::endl;
    }


    int getOldlimit() const { return m_oldlimit; }

private:
    std::string m_title;
    std::string m_support;
    int m_oldlimit;
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
    virtual void infos() const override
    {
        std::cout << "Le studio : " << m_studio << std::endl;
        std::cout << "Le pegi est de : " << m_pegi << std::endl;
        std::cout << "Le genre est de : " << m_genre << std::endl;
    }



    int getPegi() const { return m_pegi; }

private:
    std::string m_title;
    std::string m_studio;
    int m_pegi;
    std::string m_genre;
};
