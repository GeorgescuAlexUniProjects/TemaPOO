#include "Tema_1.h"
#include "carte.h"
#include "editura.h"
#include "autor.h"

int main()
{
	std::ifstream date_carte("carte.txt");
	std::string nume_carte, nume_autor, nume_editura;
	std::getline(date_carte, nume_carte, ' ');
	int nr_volume, aux_i;
	float aux_f;
	std::vector<int> nr_pagini_vol;
	std::vector<float> rating_vol;
	date_carte >> nr_volume;
	for (int i = 0; i < nr_volume; i++)
	{
		date_carte >> aux_i;
		nr_pagini_vol.push_back(aux_i);
		date_carte >> aux_f;
		rating_vol.push_back(aux_f);
	}
	date_carte.close();
	carte c(nume_carte, nr_volume, nr_pagini_vol, rating_vol);
	std::ifstream date_editura("editura.txt");
	std::getline(date_editura, nume_editura);
	editura e(nume_editura);
	date_editura.close();
	std::ifstream date_autor("autor.txt");
	std::getline(date_autor, nume_autor);
	date_autor.close();
	autor a(nume_autor);
	carte c1 = c;
	carte c2(nume_carte, nr_volume, nr_pagini_vol, rating_vol);
	c2 = c;
	std::cout << c;
	editura e1 = e;
	editura e2(nume_editura);
	e2 = e;
	std::cout << e;
	autor a1 = a;
	autor a2(nume_autor);
	a2 = a;
	std::cout << a;
	c.afisare();
	e.afisare();
	a.afisare();
	return 0;
}