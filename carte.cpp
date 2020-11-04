#include "carte.h"

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