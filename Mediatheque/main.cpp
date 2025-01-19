#include "Mediatheque.h"
#include "InputCommand.h"

int main()
{
    Mediatheque mediatheque;
    /*Client* client1 = new Client("Dupont", "Jean", 25, "123 rue Example", 123456789, "jean@email.com");
    mediatheque.addClient(client1);

    Client* client2 = new Client("Dupont", "charlotte", 20, "123 rue Example", 123456789, "jean@email.com");
    mediatheque.addClient(client2);

    Book* book1 = new Book("mortel Adele", 232);
    mediatheque.addMedia(book1);

    Movie* movie1 = new Movie("Avatar", "DVD", 18);
    mediatheque.addMedia(movie1);

    Movie* movie2 = new Movie("hp", "DVD", 18);
    mediatheque.addMedia(movie2);

    Movie* movie3 = new Movie("star wars", "DVD", 18);
    mediatheque.addMedia(movie3);

    Movie* movie4 = new Movie("matrix", "DVD", 18);
    mediatheque.addMedia(movie4);

    Movie* movie5 = new Movie("lord of the ring", "DVD", 18);
    mediatheque.addMedia(movie5);
*/


    ////mediatheque.showClient();
    ////mediatheque.showMedia();

    ////mediatheque.removeClient("Dupont", "charlotte", "");


    ////mediatheque.showClient();
    //mediatheque.showMedia();/*
    //mediatheque.borrow(client1, book1);*/
    //mediatheque.showMedia();/*
    //mediatheque.removeMedia("Movie", "Avatar");*/
    ////mediatheque.removeMedia("Movie", "Avatar");

    //mediatheque.borrow(client2, movie1);
    //mediatheque.borrow(client2, movie1); 
    //mediatheque.borrow(client2, movie2); 
    //mediatheque.borrow(client2, movie3); 
    //mediatheque.borrow(client2, movie4); 
    //mediatheque.borrow(client2, movie5); 
    // 
    ////mediatheque.giveBack(client2, movie1);
    //mediatheque.giveBack(client1, book1);
    //mediatheque.removeClient("Dupont", "charlotte", "");

    ////mediatheque.showBorrowMedia();
    ////mediatheque.showAvailableMedia();

    //mediatheque.showStateMedia(movie3);

    ////mediatheque.ShowWhoMedia(movie1);
    //mediatheque.showMedia(); 
    //mediatheque.ShowWhatMedia(client2);

    std::vector<std::string> instructionList =
    {
         "addClient Dupont Jean 25 rue 123456789 jean@email.com"
        ,"listClient"
        ,"removeClient Dupont Jean jean@email.com"
        ,"listClient"
    };


    while (!instructionList.empty())
    {
        std::string instruction = instructionList.front();
        instructionList.erase(instructionList.begin());

        try
        {
            mediatheque.process(instruction);
        }
        catch (std::runtime_error& e)
        {
            std::cerr << e.what();
            return 0;
        }

        ::getchar();
    }

    return 0;
}