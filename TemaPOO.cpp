#include "TemaPOO.h"
#include "carte.h"
#include "editura.h"
#include "autor.h"

int main()
{
	std::ifstream date_carte("../../../info_carte.txt");
	std::string nume_carte, nume_autor, nume_editura;
	std::getline(date_carte, nume_carte, ' ');
	int nr_volume = 0;
	date_carte >> nr_volume;
	int aux_pagini = 0;
	float aux_rating = 0;
	auto nr_pagini_vol = std::make_unique<std::vector<int>>();
	auto rating_vol = std::make_unique<std::vector<float>>();
	/*std::vector<int> nr_pagini_vol = {};
	std::vector<float> rating_vol = {};*/
	for (int i = 0; i < nr_volume; i++)
	{
		date_carte >> aux_pagini;
		/*nr_pagini_vol.emplace_back(aux_pagini);*/
		nr_pagini_vol->emplace_back(aux_pagini);
		date_carte >> aux_rating;
		/*rating_vol.emplace_back(aux_rating);*/
		rating_vol->emplace_back(aux_rating);
	}
	date_carte.close();
	carte c(nume_carte, nr_volume, *nr_pagini_vol, *rating_vol);
	std::ifstream date_editura("../../../info_editura.txt");
	std::getline(date_editura, nume_editura);
	editura e(nume_editura);
	date_editura.close();
	std::ifstream date_autor("../../../info_autor.txt");
	std::getline(date_autor, nume_autor);
	date_autor.close();
	autor a(nume_autor);
	editura e1 = e;
	editura e2(nume_editura);
	e2 = e;
	std::cout << e;
	e.afisare();
	a.afisare();
	c.afisare();
	return 0;
}