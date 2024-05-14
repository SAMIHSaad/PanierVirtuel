
#include "Panier.h"
#include "Client.h"

class Commande
{
private:
    static int nbr;
    int numero;
    Panier panier; 
    Client client; 
public:
    Commande(Client& client, Panier& panier);
    int getNumero() const;
    const string& getClient() const;
    double getMontantTotal() const; 
    const Panier& getPanier() const; 
    void setCommande(Client& client, Panier& panier);

};

