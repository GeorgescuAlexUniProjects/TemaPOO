#include "editura.h"

//editura::editura(std::string nume_editura)
//{
//	this->nume_editura = nume_editura;
//	std::cout << "Constructor editura" << std::endl;
//}

editura::editura(editura& cc)
{
	this->nume_editura = cc.nume_editura;
	//std::cout << "Constructor copiere editura" << std::endl;
}

editura::~editura()
{
	//std::cout << "Destructor editura" << std::endl;
}

editura& editura::operator=(const editura& eop)
{
	//std::cout << "Operator=(Nume editura) " << nume_editura << "=" << eop.nume_editura << std::endl;
	this->nume_editura = eop.nume_editura;
	return *this;
}

void editura::afisare()
{
	//std::cout << "Editura: " << nume_editura << std::endl;
}

std::ostream& operator<<(std::ostream& out, const editura& editura)
{
	//out << "Operator<<(Nume editura) " << editura.nume_editura << std::endl;
	out << editura.nume_editura;// << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, editura& editura)
{
	in >> editura.nume_editura;
	return in;
}