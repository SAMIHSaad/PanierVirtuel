#ifndef ARTICLE_H
#define ARTICLE_H

#include<string>
#include<iostream>
using namespace std;

class Article
{
private:
	string ref;
	double prix;
	int qte;
public:
	Article(const string& reference, double prix, int qt);
	const string& getReference() const;
	double getPrix() const;
	int getStock() const;
	void setStock(int newStock);
	bool checkandupdate(int quantity);
};

#endif
