#pragma once
#include <iostream>

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