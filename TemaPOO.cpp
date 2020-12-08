#include "TemaPOO.h"
#include "carte.h"
#include "editura.h"
#include "autor.h"

int main()
{
	std::ifstream date_carte("../../../info_carte.txt");
	std::string nume_carte, nume_autor, nume_editura;
	std::getline(date_carte, nume_carte, ' ');
	int nr_volume;
	date_carte >> nr_volume;
	/*std::vector<std::shared_ptr<int>> nr_pagini_vol;
	std::vector<std::shared_ptr<float>> rating_vol;*/
	std::shared_ptr<int[]> nr_pagini_vol(new int[nr_volume]);
	std::shared_ptr<float[]> rating_vol(new float[nr_volume]);
	for (int i = 0; i < nr_volume; i++)
	{
		/*date_carte >> aux_i;
		nr_pagini_vol.emplace_back(aux_i);*/
		date_carte >> nr_pagini_vol[i];
		try
		{
			if (nr_pagini_vol[i] < 0)
			{
				throw std::exception();
			}
		}
		catch (std::exception& err_pagini)
		{
			std::cout << "Exceptie pe valoare: " << nr_pagini_vol[i] << std::endl << "Valoare negativa";
			std::cerr << err_pagini.what() << std::endl;
			return -1;
		}
		/*date_carte >> aux_f;
		rating_vol.emplace_back(aux_f);*/
		date_carte >> rating_vol[i];
		try
		{
			if (rating_vol[i] > 10 || rating_vol[i] < 0)
			{
				throw std::exception();
			}
		}
		catch (std::exception& err_rating)
		{
			std::cout << "Exceptie pe valoare: " << rating_vol[i] << std::endl;
			if (rating_vol[i] > 10)
			{
				std::cout << "Valoare rating prea mare";
			}
			else
			{
				std::cout << "Valoare rating prea mica";
			}
			std::cerr << err_rating.what() << std::endl;
			return -1;
		}
	}
	date_carte.close();
	carte c(nume_carte, nr_volume, nr_pagini_vol, rating_vol);
	std::ifstream date_editura("../../info_editura.txt");
	std::getline(date_editura, nume_editura);
	editura e(nume_editura);
	date_editura.close();
	std::ifstream date_autor("../../info_autor.txt");
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