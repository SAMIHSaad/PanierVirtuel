#include "Article.h"

Article::Article(const string& reference, double prix, int qt) : ref(reference), prix(prix), qte(qt) {}

const string& Article::getReference() const {
    return ref;
}

double Article::getPrix() const {
    return prix;
}

int Article::getStock() const {
    return qte;
}

void Article::setStock(int newStock)
{
    qte = newStock;
}

bool Article::checkandupdate(int quantity)
{
    if (getStock() >= quantity) 
    {
        setStock(getStock() - quantity);
        return true;
    }
    return false;
}
