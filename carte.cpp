#include "carte.h"

carte::carte(std::string nume_carte, int nr_volume, std::shared_ptr<int[]> nr_pagini_vol, std::shared_ptr<float[]> rating_vol)
{
	this->nume_carte = nume_carte;
	this->nr_volume = nr_volume;
	this->nr_pagini_vol = nr_pagini_vol;
	this->rating_vol = rating_vol;
	//std::cout << "Constructor carte" << std::endl;
}

//carte::carte(carte& cc)
//{
//	this->nume_carte = cc.nume_carte;
//	this->nr_volume = cc.nr_volume;
//	this->nr_pagini_vol = cc.nr_pagini_vol;
//	this->rating_vol = cc.rating_vol;
//	std::cout << "Constructor copiere carte" << std::endl;
//}

carte::~carte()
{
	//std::cout << "Destructor carte" << std::endl;
}

//carte& carte::operator=(const carte& eop)
//{
//	std::cout << "Operator=(Nume carete) " << nume_carte << "=" << eop.nume_carte << std::endl;
//	this->nume_carte = eop.nume_carte;
//	std::cout << "Operator=(Numar volume) " << nr_volume << "=" << eop.nr_volume << std::endl;
//	this->nr_volume = eop.nr_volume;
//	for (int i = 0; i < nr_volume; i++)
//	{
//		std::cout << "Operator=(Numar pagini volum) " << nr_pagini_vol[i] << "=" << eop.nr_pagini_vol[i] << std::endl;
//	}
//	this->nr_pagini_vol = eop.nr_pagini_vol;
//	for (int i = 0; i < nr_volume; i++)
//	{
//		std::cout << "Operator=(Rating volum) " << rating_vol[i] << "=" << eop.rating_vol[i] << std::endl;
//	}
//	this->rating_vol = eop.rating_vol;
//	return *this;
//}

int carte::Nr_total_pagini(int nr_pagini_total)
{
	nr_pagini_total = 0;
	for (int i = 0; i < nr_volume; i++)
	{
		nr_pagini_total = nr_pagini_total + nr_pagini_vol[i];
	}
	return nr_pagini_total;
}

float carte::Medie_rating(float medie_rating)
{
	int rating_total = 0;
	for (int i = 0; i < nr_volume; i++)
	{
		rating_total = rating_total + rating_vol[i];
	}
	medie_rating = static_cast<float>(rating_total) / nr_volume;
	try
	{
		if (medie_rating < 0 || medie_rating > 10)
		{
			throw std::exception();
		}
	}
	catch (std::exception& err_medie_rating)
	{
		std::cout << "Exceptie pe valoare: " << medie_rating << std::endl;
		if (medie_rating < 10)
		{
			std::cout << "Medie rating-ul este prea mare";
		}
		else
		{
			std::cout << "Medie rating-ul este prea mica";
		}
		std::cerr << err_medie_rating.what() << std::endl;
		return -1;
	}
	return medie_rating;
}

float carte::Medie_pagini(float medie_pagini, int nr_pagini_total)
{
	medie_pagini = static_cast<float>(Nr_total_pagini(nr_pagini_total)) / nr_volume;
	try
	{
		if (medie_pagini < 0)
		{
			throw std::exception();
		}
	}
	catch (std::exception& err_medie_pagini)
	{
		std::cout << "Exceptie in calcul medie paginilor: " << medie_pagini << std::endl << "Media de pagini este negativa";
		std::cerr << err_medie_pagini.what() << std::endl;
		return -1;
	}
	return medie_pagini;
}

void carte::afisare()
{
	std::cout << "Carte: " << nume_carte << std::endl << "\tNumar volume: " << nr_volume << std::endl;
	std::cout << "\tNumar pagini / Rating pe volum" << std::endl;
	for (int i = 0; i < nr_volume; i++)
	{
		std::cout << "\t\t" << i << ": " << nr_pagini_vol[i] << " / " << rating_vol[i] << std::endl;
	}
	std::cout << "\t\tNumar total de pagini: " << Nr_total_pagini(nr_pagini_total) << std::endl;
	std::cout << "\t\tMedie pagini: " << Medie_pagini(medie_pagini, nr_pagini_total) << std::endl;
	std::cout << "\t\tMedie rating: " << Medie_rating(medie_rating) << std::endl;
}

std::ostream& operator<<(std::ostream& out, const carte& carte)
{
	out << "Operator<<(Nume carete) " << carte.nume_carte << std::endl;
	out << "Operator<<(Numar volum)  " << carte.nr_volume << std::endl;
	for (int i = 0; i < carte.nr_volume; i++)
	{
		out << "Operator<<(Numar pagini)  " << carte.nr_pagini_vol[i] << std::endl;
		out << "Operator<<(Rating volum)  " << carte.rating_vol[i] << std::endl;
	}
	return out;
}