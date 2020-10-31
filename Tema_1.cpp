#include "Tema_1.h"

class carte
{
private:
	std::string nume_carte;
	int nr_pagini,nr_volum;
public:
	carte(std::string nume_carte, int nr_pagini, int nr_volum);
	carte(carte& cc);
	~carte();
	carte& operator=(const carte& eop);
	friend std::ostream& operator<<(std::ostream& out, const carte& carte)
	{
		out << "Nume carte: " << carte.nume_carte << std::endl;
		out << "Numar pagini: " << carte.nr_pagini << std::endl;
		out << "Numar volum: " << carte.nr_volum << std::endl;
		return out;
	}
	void afisare()
	{
		std::cout << nume_carte << std::endl << "Volum: " << nr_volum << std::endl << "Numar pagini: " << nr_pagini << std::endl;

	}
};

carte::carte(std::string nume_carte, int nr_pagini, int nr_volum)
{
	this->nume_carte = nume_carte;
	this->nr_pagini = nr_pagini;
	this->nr_volum = nr_volum;
	std::cout << "Constructor carte" << std::endl;
}

carte::carte(carte& cc)
{
	this->nume_carte = cc.nume_carte;
	this->nr_pagini = cc.nr_pagini;
	this->nr_volum = cc.nr_volum;
	std::cout << "Constructor copiere carte" << std::endl;
}

carte::~carte()
{
	std::cout << "Destructor carte" << std::endl;
}

carte& carte::operator=(const carte& eop)
{
	std::cout << "Operator=(carte) " << nume_carte << " " << eop.nume_carte << std::endl;
	this->nume_carte = eop.nume_carte;
	std::cout << "Operator=(carte) " << nr_pagini << " " << eop.nr_pagini << std::endl;
	this->nr_pagini = eop.nr_pagini;
	std::cout << "Operator=(carte) " << nr_volum << " " << eop.nr_volum << std::endl;
	this->nr_volum = eop.nr_volum;
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
	void afisare()
	{
		std::cout << "Editura: " << nume_editura << std::endl;

	}
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
	std::cout << "Operator=(editura) " << nume_editura << " " << eop.nume_editura << std::endl;
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
	void afisare()
	{
		std::cout << "Autor: " << nume_autor << std::endl;

	}
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
	std::cout << "Operator=(autor) " << nume_autor << " " << eop.nume_autor << std::endl;
	this->nume_autor = eop.nume_autor;
	return *this;
}

int main()
{
	carte c("Overlord",12, 288);
	editura e("Yen Press");
	autor a("Kugane Maruyama");
	c.afisare();
	e.afisare();
	a.afisare();
	return 0;
}