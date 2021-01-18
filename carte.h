#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include "autor.h"
#include "editura.h"

template <class T>
T format(float f)
{
	T form;
	if (f >= 240)
	{
		form = "Roman";
	}
	else
	{
		form = "Nuvela";
	}
	return form;
}

class carte
{
private:
	std::string coperta = "";
	std::string tip = "";
	std::string dimensiune = "";
public:
	carte() = default;
	carte(const std::string &coperta, const std::string& tip, const std::string& dimensiune)
	: coperta(coperta), tip(tip), dimensiune(dimensiune) {}
	virtual ~carte() {}
	virtual void afisare(std::ostream& out) const;
	friend std::ostream& operator<<(std::ostream& out, const carte& carte);
};

class c_fictiune : public carte
{
private:
	std::string nume_carte;
	autor nume_autor;
	editura nume_editura;
	int nr_volume = 0;
	std::vector<int> nr_pagini_vol = {};
public:
	c_fictiune(const std::string& nume_carte, autor nume_autor, editura nume_editura, int nr_volume, std::vector<int> nr_pagini_vol)
	: nume_carte(nume_carte), nume_autor(nume_autor), nume_editura(nume_editura), nr_volume(nr_volume), nr_pagini_vol(nr_pagini_vol) {}
	virtual ~c_fictiune() {};
	int Nr_total_pagini() const;
	float Medie_pagini() const;
	void afisare(std::ostream& out) const override;
};

class carte_factory
{
public:
	static carte fic_hc()
	{
		return carte("hard cover", "fictiune", "A5");
	}
	static carte fic_pc()
	{
		return carte("paper cover", "fictiune", "A5");
	}
	static carte nfic_hc5()
	{
		return carte("hard cover", "non-fictiune", "A5");
	}
	static carte nfic_pc5()
	{
		return carte("paper cover", "non-fictiune", "A5");
	}
	static carte nfic_pc4()
	{
		return carte("paper cover", "non-fictiune", "A4");
	}
};

class c_n_fictiune : public carte
{
private:
	std::string nume_carte;
	autor nume_autor;
	editura nume_editura;
	int nr_pagini = 0;
public:
	c_n_fictiune(const std::string& nume_carte, autor nume_autor, editura nume_editura, int nr_pagini)
	: nume_carte(nume_carte), nume_autor(nume_autor), nume_editura(nume_editura), nr_pagini(nr_pagini) {}
	virtual ~c_n_fictiune() {};
	void afisare(std::ostream& out) const override;
};