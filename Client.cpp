#include "Client.h"

Client::Client(const string& email, const string& name) : email(email), name(name) {}


const std::string& Client::getEmail() const
{
    return email;
}

const std::string& Client::getName() const
{
    return name;
}

const Panier& Client::getPanier() const
{
    return panier;
}

void Client::setPanier(const Panier& panier)
{
    this->panier = panier;
}