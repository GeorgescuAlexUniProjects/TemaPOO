#pragma once
#include "Tema_1.h"

class autor
{
private:
	std::string nume_autor;
public:
	autor(std::string nume_autor);
	//autor(autor& cc);
	~autor();
	//autor& operator=(const autor& eop);
	friend std::ostream& operator<<(std::ostream& out, const autor& autor);
	void afisare();
};