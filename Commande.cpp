#include "Commande.h"
using namespace std;
int Commande::nbr = 0;
Commande::Commande(Client& client, Panier& panier) : numero(++nbr), panier(panier), client(client) {}


int Commande::getNumero() const
{
    return numero;
}


const string& Commande::getClient() const
{
    return client.getName();
}


double Commande::getMontantTotal() const
{
    double montantTotal = 0.0;
    for (auto pair : panier.getArticles())
    {
        Article* article = pair.first;
        int quantiteCommandee = pair.second;
        double prix = article->getPrix();
        double montantArticle = prix * quantiteCommandee;
        if (quantiteCommandee > 10)
        {
           montantArticle *= 0.8;
        }
         montantTotal += montantArticle;
    }
    return montantTotal;
}

const Panier& Commande::getPanier() const
{
    return panier;
}

void Commande::setCommande(Client& client, Panier& panier)
{
    this->client = client;
    this->panier = panier;
}