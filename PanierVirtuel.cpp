#include <iostream>
#include <string>
#include <vector>
#include "Commande.h"
#include "Article.h"
#include "Panier.h"
#include "Client.h"

using namespace std;
bool isArticleReferenceFound(const vector<Article>& articles, const string& reference)
{
    for (const auto& a : articles) {
        if (a.getReference() == reference) {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<Article> articles = {
        Article("A1", 0.5, 100),
        Article("B2", 0.25, 200),
        Article("C3", 1.0, 50)
    };

    Panier panier;
    Client client("john.doe@example.com", "John Doe");
    vector<Commande> commandes;
    while (true) 
    {
        cout << "\nBienvenue dans le menu du Simple Epicerie!\n";
        cout << "1. Ajouter un article au panier\n";
        cout << "2. Supprimer un article du panier\n";
        cout << "3. Modifier la quantite d'un article dans le panier\n";
        cout << "4. Voir le panier\n";
        cout << "5. Voir les details de la commande\n";
        cout << "6. Quitter\n";
        cout << "Entrez votre choix : ";
        int choix;
        cin >> choix;
        client.setPanier(panier);
        system("cls");
        switch (choix) {
        case 1: {
            cout << "Entrez la reference de l'article : ";
            string ref;
            cin >> ref;
            if (!isArticleReferenceFound(articles, ref)) {
                cout << "Article non trouvé. Veuillez réessayer.\n";
                break;
            }

            Article* article = nullptr;
            for (auto& a : articles) {
                if (a.getReference() == ref) {
                    article = &a;
                    break;
                }
            }
            if (article == nullptr) {
                cout << "Erreur interne. Veuillez réessayer.\n";
                break;
            }
            cout << "Entrez la quantité de l'article : ";
            int qt;
            cin >> qt;
            if (qt > article->getStock()) {
                cout << "La quantite demandee depasse la quantité disponible. Veuillez reessayer.\n";
                break;
            }
            panier.ajouterArticle(*article, qt);
            Commande commande(client, panier);
            commandes.push_back(commande);
            cout << "Article ajoute au panier avec succes! Sous la commande numero" << commande.getNumero();
            break;
        }
       
        case 2: {
            cout << "Entrez la reference de l'article a supprimer : ";
            string ref;
            cin >> ref;
            if (!isArticleReferenceFound(articles, ref)) {
                cout << "Article non trouve. Veuillez reessayer.\n";
                break;
            }
            panier.enleverArticle(ref);
            cout << "Article supprime du panier et du vecteur avec succes!\n";
            break;
        }

        case 3: {
            cout << "Entrez la reference de l'article a modifier : ";
            string ref;
            cin >> ref;
            if (!isArticleReferenceFound(articles, ref)) {
                cout << "Article non trouve. Veuillez reessayer.\n";
                break;
            }
            int cmd;
            cout << "Entrez le numero de la commande";
            cin >> cmd;
            cout << "Entrez la nouvelle quantité : ";
            int qt;
            cin >> qt;
            panier.modifierQuantite(ref, qt);
            cout << "Quantite modifiée avec succes!\n";
            Commande* commande = nullptr;
            for (auto& c : commandes) {
                if (c.getNumero() == cmd) {
                    commande = &c;
                    break;
                }
                }
            commande->setCommande(client, panier);
            break;
        }

        case 4: {
            cout << "Panier pour " << client.getName() << ":\n";
            for (auto& pair : client.getPanier().getArticles())
            {
                Article* article = pair.first;
                int quantiteCommandee = pair.second;
                std::cout << " - " << article->getReference() << " (" << quantiteCommandee << ")" << endl;
            }
            break;
        }
        case 5: {
            std::cout << "Entrez le numéro de commande : ";
            int num;
            std::cin >> num;

            auto it = find_if(commandes.begin(), commandes.end(),
                [num](const Commande& commande) { return commande.getNumero() == num; });

            if (it != commandes.end()) {
                std::cout << "Details de la commande :\n";
                std::cout << " - Numéro de commande: " << it->getNumero() << "\n";
                std::cout << " - Client: " << it->getClient() << "\n";
                std::cout << " - Montant total: " << it->getMontantTotal() << "\n";
            }
            else {
                std::cout << "Aucune commande trouvée avec le numéro " << num << "\n";
            }
            break;
        }

        case 6: {
            cout << "Au revoir!\n";
            return 0;
        }
        default:
            cout << "Choix invalide. Veuillez réessayer.\n";
        }
    }
}