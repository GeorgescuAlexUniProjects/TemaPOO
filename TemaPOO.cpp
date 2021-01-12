#include "TemaPOO.h"
#include "carte.h"
#include "editura.h"
#include "autor.h"

int main()
{
	std::vector<carte*> carte;
	std::ifstream date_carte("informati.txt");
	int nr_carti = 0, nr_volume = 0, nr_pagini = 0;
	std::vector<int> pagini;
	std::string tip_carte, nume_carte;
	date_carte >> nr_carti;
	for(int i = 0; i < nr_carti; i++)
	{
		autor n_autor;
		editura n_editura;
		date_carte >> tip_carte;
		if(tip_carte == "fictiune")
		{
			date_carte >> nume_carte >> n_autor >> n_editura >> nr_volume;
			for (int i = 0; i < nr_volume; i++)
			{
				date_carte >> nr_pagini;
				pagini.push_back(nr_pagini);
			}
			carte.push_back(new c_fictiune(nume_carte, n_autor, n_editura, nr_volume, pagini));
		}
		else if (tip_carte == "non-fictiune")
		{
			date_carte >> nume_carte >> n_autor >> n_editura >> nr_pagini;
			carte.push_back(new c_n_fictiune(nume_carte, n_autor, n_editura, nr_pagini));
		}
	}
	for (int i = 0; i < nr_carti; i++)
	{
		std::cout << *carte[i];
	}
	for (int i = 0; i < nr_carti; i++)
	{
		delete carte[i];
	}
	return 0;
}