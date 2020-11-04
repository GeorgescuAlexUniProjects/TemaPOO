#include "Tema_1.h"

class carte
{
private:
	std::string nume_carte;
	int nr_volum, nr_pagini;
public:
	carte(std::string nume_carte, int nr_volum, int nr_pagini);
	carte(carte& cc);
	~carte();
	carte& operator=(const carte& eop);
	friend std::ostream& operator<<(std::ostream& out, const carte& carte);
	void afisare();
};

carte::carte(std::string nume_carte, int nr_volum, int nr_pagini)
{
	this->nume_carte = nume_carte;
	this->nr_volum = nr_volum;
	this->nr_pagini = nr_pagini;
	std::cout << "Constructor carte" << std::endl;
}

carte::carte(carte& cc)
{
	this->nume_carte = cc.nume_carte;
	this->nr_volum = cc.nr_volum;
	this->nr_pagini = cc.nr_pagini;
	std::cout << "Constructor copiere carte" << std::endl;
}

carte::~carte()
{
	std::cout << "Destructor carte" << std::endl;
}

carte& carte::operator=(const carte& eop)
{
	std::cout << "Operator=(Nume carete) " << nume_carte << "=" << eop.nume_carte << std::endl;
	this->nume_carte = eop.nume_carte;
	std::cout << "Operator=(Numar volum) " << nr_volum << "=" << eop.nr_volum << std::endl;
	this->nr_volum = eop.nr_volum;
	std::cout << "Operator=(Numar pagini) " << nr_pagini << "=" << eop.nr_pagini << std::endl;
	this->nr_pagini = eop.nr_pagini;
	return *this;
}

void carte::afisare()
{
	std::cout << nume_carte << std::endl << "Volum: " << nr_volum << std::endl << "Numar pagini: " << nr_pagini << std::endl;
}

std::ostream& operator<<(std::ostream& out, const carte& carte)
{
	out << "Operator<<(Nume carete) " << carte.nume_carte << std::endl;
	out << "Operator<<(Numar volum)  " << carte.nr_volum << std::endl;
	out << "Operator<<(Numar pagini)  " << carte.nr_pagini << std::endl;
	return out;
}

class editura
{
private:
	std::string nume_editura;
public:
	editura(std::string nume_editura);
	editura(editura& cc);
	~editura();
	editura& operator=(const editura& eop);
	friend std::ostream& operator<<(std::ostream& out, const editura& editura);
	void afisare();
};

editura::editura(std::string nume_editura)
{
	this->nume_editura = nume_editura;
	std::cout << "Constructor editura" << std::endl;
}

editura::editura(editura& cc)
{
	this->nume_editura = cc.nume_editura;
	std::cout << "Constructor copiere editura" << std::endl;
}

editura::~editura()
{
	std::cout << "Destructor editura" << std::endl;
}

editura& editura::operator=(const editura& eop)
{
	std::cout << "Operator=(Nume editura) " << nume_editura << "=" << eop.nume_editura << std::endl;
	this->nume_editura = eop.nume_editura;
	return *this;
}

void editura::afisare()
{
	std::cout << "Editura: " << nume_editura << std::endl;
}

std::ostream& operator<<(std::ostream& out, const editura& editura)
{
	out << "Operator<<(Nume editura) " << editura.nume_editura << std::endl;
	return out;
}

class autor
{
private:
	std::string nume_autor;
public:
	autor(std::string nume_autor);
	autor(autor& cc);
	~autor();
	autor& operator=(const autor& eop);
	friend std::ostream& operator<<(std::ostream& out, const autor& autor);
	void afisare();
};

autor::autor(std::string nume_autor)
{
	this->nume_autor = nume_autor;
	std::cout << "Constructor autor" << std::endl;
}

autor::autor(autor& cc)
{
	this->nume_autor = cc.nume_autor;
	std::cout << "Constructor copiere autor" << std::endl;
}

autor::~autor()
{
	std::cout << "Destructor autor" << std::endl;
}

autor& autor::operator=(const autor& eop)
{
	std::cout << "Operator=(Nume autor) " << nume_autor << "=" << eop.nume_autor << std::endl;
	this->nume_autor = eop.nume_autor;
	return *this;
}

void autor::afisare()
{
	std::cout << "Autor: " << nume_autor << std::endl;
}

std::ostream& operator<<(std::ostream& out, const autor& autor)
{
	out << "Operator<<(Nume autor) " << autor.nume_autor << std::endl;
	return out;
}

int main()
{
	carte c("Overlord",12, 288);
	editura e("Yen Press");
	autor a("Kugane Maruyama");
	carte c1 = c;
	carte c2("c", 1, 1);
	c2 = c;
	std::cout << c;
	editura e1 = e;
	editura e2("e");
	e2 = e;
	std::cout << e;
	autor a1 = a;
	autor a2("a");
	a2 = a;
	std::cout << a;
	c.afisare();
	e.afisare();
	a.afisare();
	return 0;
}