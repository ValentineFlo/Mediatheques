#pragma once
#include <iostream>
#include <vector>

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
        , m_borrowcounter(1)
    {
    }

    int getBorrowcounter() { return m_borrowcounter; }
    int getAddBorrowcounter() { return m_borrowcounter++; }
    int getSubBorrowcounter() { if (m_borrowcounter > 0) return m_borrowcounter--; }


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
    int m_borrowcounter;
};
