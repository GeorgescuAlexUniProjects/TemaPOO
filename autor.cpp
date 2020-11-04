#include "autor.h"

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