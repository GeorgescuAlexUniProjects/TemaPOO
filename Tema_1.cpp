#include "Tema_1.h"

class carte
{
private:
	std::string nume_carte;
	int nr_pagini;
public:
	carte(std::string nume_carte, int nr_pagini);
	carte(carte& cc);
	~carte();
	carte& operator=(const carte& eop);
	friend std::ostream& operator<<(std::ostream& out, const carte& carte)
	{
		out << "Nume carte: " << carte.nume_carte << std::endl;
		out << "Numar pagini: " << carte.nr_pagini << std::endl;
		return out;
	}
};

carte::carte(std::string nume_carte, int nr_pagini)
{
	this->nume_carte = nume_carte;
	this->nr_pagini = nr_pagini;
	std::cout << "Constructor" << std::endl;
}

carte::carte(carte& cc)
{
	this->nume_carte = cc.nume_carte;
	this->nr_pagini = cc.nr_pagini;
	std::cout << "Constructor copiere" << std::endl;
}

carte::~carte()
{
	std::cout << "Destructor" << std::endl;
}

carte& carte::operator=(const carte& eop)
{
	std::cout << "Operator=" << nume_carte << " " << eop.nume_carte << std::endl;
	this->nume_carte = eop.nume_carte;
	std::cout << "Operator=" << nr_pagini << " " << eop.nr_pagini << std::endl;
	this->nr_pagini = eop.nr_pagini;
	return *this;
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
	friend std::ostream& operator<<(std::ostream& out, const editura& editura)
	{
		out << "Nume editura: " << editura.nume_editura << std::endl;
		return out;
	}
};

editura::editura(std::string nume_editura)
{
	this->nume_editura = nume_editura;
	std::cout << "Constructor" << std::endl;
}

editura::editura(editura& cc)
{
	this->nume_editura = cc.nume_editura;
	std::cout << "Constructor copiere" << std::endl;
}

editura::~editura()
{
	std::cout << "Destructor" << std::endl;
}

editura& editura::operator=(const editura& eop)
{
	std::cout << "Operator=" << nume_editura << " " << eop.nume_editura << std::endl;
	this->nume_editura = eop.nume_editura;
	return *this;
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
	friend std::ostream& operator<<(std::ostream& out, const autor& autor)
	{
		out << "Nume autor: " << autor.nume_autor << std::endl;
		return out;
	}
};

autor::autor(std::string nume_autor)
{
	this->nume_autor = nume_autor;
	std::cout << "Constructor" << std::endl;
}

autor::autor(autor& cc)
{
	this->nume_autor = cc.nume_autor;
	std::cout << "Constructor copiere" << std::endl;
}

autor::~autor()
{
	std::cout << "Destructor" << std::endl;
}

autor& autor::operator=(const autor& eop)
{
	std::cout << "Operator=" << nume_autor << " " << eop.nume_autor << std::endl;
	this->nume_autor = eop.nume_autor;
	return *this;
}

int main()
{
	carte c("Overlord Vol. 12", 288);
	editura e("Yen Press");
	autor a("Kugane Maruyama");
	return 0;
}