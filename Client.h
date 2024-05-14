#ifndef CLIENT_H
#define CLIENT_H
#include "Panier.h"
using namespace std;
class Client {
private:
    string email;
    string name;
    Panier panier;
public:
    Client(const string& email, const string& name);
    const string& getEmail() const;
    const string& getName() const;
    const Panier& getPanier() const;
    void setPanier(const Panier& panier);
};
#endif