#include "Mediatheque.h"

int main()
{
    Mediatheque mediatheque;

    Client* client1 = new Client("Dupont", "Jean", 25, "123 rue Example", 123456789, "jean@email.com");
    mediatheque.addClient(client1);

    Client* client2 = new Client("Dupont", "charlotte", 25, "123 rue Example", 123456789, "jean@email.com");
    mediatheque.addClient(client2);

    Book* book1 = new Book("mortel Adele", 232);
    mediatheque.addMedia(book1);

    Movie* movie1 = new Movie("Avatar", "DVD", 18);
    mediatheque.addMedia(movie1);

    mediatheque.showClient();
    mediatheque.showMedia();

    mediatheque.removeClient("Dupont", "charlotte", "");
    mediatheque.removeMedia("Movie", "Avatar");

    mediatheque.showClient();
    mediatheque.showMedia();

    return 0;
}