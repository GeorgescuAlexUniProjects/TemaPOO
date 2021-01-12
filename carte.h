#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include "autor.h"
#include "editura.h"

class carte
{
private:
	std::string nume_carte;
	autor nume_autor;
	editura nume_editura;
public:
	carte(const std::string &nume_carte, autor nume_autor, editura nume_editura)
	: nume_carte(nume_carte), nume_autor(nume_autor), nume_editura(nume_editura) {}
	virtual ~carte() {}
	virtual void afisare(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const carte& carte);
};

class c_fictiune : public carte
{
private:
	int nr_volume = 0;
	std::vector<int> nr_pagini_vol = {};
public:
	c_fictiune(const std::string& nume_carte, autor nume_autor, editura nume_editura, int nr_volume, std::vector<int> nr_pagini_vol)
	: carte(nume_carte, nume_autor, nume_editura), nr_volume(nr_volume), nr_pagini_vol(nr_pagini_vol) {}
	virtual ~c_fictiune() {};
	int Nr_total_pagini() const;
	float Medie_pagini() const;
	void afisare(std::ostream& out) const override;
};

class c_n_fictiune : public carte
{
private:
	int nr_pagini = 0;
public:
	c_n_fictiune(const std::string& nume_carte, autor nume_autor, editura nume_editura, int nr_pagini)
	: carte(nume_carte, nume_autor, nume_editura), nr_pagini(nr_pagini) {}
	virtual ~c_n_fictiune() {};
	void afisare(std::ostream& out) const override;
};