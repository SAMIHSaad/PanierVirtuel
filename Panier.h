#ifndef PANIER_H
#define PANIER_H

#include <map>
#include<vector>
#include "Article.h"

class Panier
{
private:
    map<Article*, int> articles;
public:
    void ajouterArticle(Article& article, int quantity);
    void modifierQuantite(const string& reference, int newQuantity);
    void enleverArticle(const string& reference);
    void viderPanier();
    int getQuantiteCommandee(const string& reference) const;
    const map<Article*, int>& getArticles() const;
};

#endif // PANIER_H
