#include "Panier.h"
#include <algorithm>

void Panier::ajouterArticle(Article& article, int quantite)
{
    if (article.checkandupdate(quantite)) {
        articles[const_cast<Article*>(&article)] = quantite;
    }
    else {
        cout << "La quantité demandée dépasse la quantité disponible. Veuillez réessayer.\n";
    }
}

void Panier::modifierQuantite(const std::string& reference, int quantite)
{
    for (auto& it : articles) 
    {
        if (it.first->getReference() == reference)
        {
            if ((it.first->getStock() - quantite) >= 0)
            {
                it.second = quantite;
                it.first->setStock(it.first->getStock() - quantite);
            }
            break;
        }
    }
}

void Panier::enleverArticle(const string& reference)
{
    for (auto it = articles.begin(); it != articles.end(); ++it)
    {
        if (it->first->getReference() == reference)
        {
            articles.erase(it);
            break; 
        }
    }
}


void Panier::viderPanier()
{
    articles.clear();
}


int Panier::getQuantiteCommandee(const string& reference) const
{
    for (auto& it : articles)
    {
        if (it.first->getReference() == reference)
        {
            return it.second;
        }
    }
    return 0;
}

const map<Article*, int>& Panier::getArticles() const
{
    return articles;
}
