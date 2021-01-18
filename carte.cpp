#include "carte.h"

void carte::afisare(std::ostream& out) const
{
	out << "Coperta: " << coperta << std::endl;
	out << "Tip: " << tip << std::endl;
	out << "Dimensiune: " << dimensiune << std::endl;
}

std::ostream& operator<<(std::ostream& out, const carte& carte)
{
	carte.afisare(out);
	return out;
}

int c_fictiune::Nr_total_pagini() const
{
	int nr_pagini_total = 0;
	for (int i = 0; i < nr_volume; i++)
	{
		nr_pagini_total = nr_pagini_total + nr_pagini_vol[i];
	}
	return nr_pagini_total;
}

float c_fictiune::Medie_pagini() const
{
	float medie_pagini = 0;
	medie_pagini = static_cast<float>(Nr_total_pagini()) / nr_volume;
	if (medie_pagini < 0)
	{
		throw std::runtime_error("Numar negativ de pagini");
	}
	return medie_pagini;
}

void c_fictiune::afisare(std::ostream& out) const
{
	carte::afisare(out);
	out << "Carte: " << nume_carte << std::endl;
	out << "\tAutor: " << nume_autor << std::endl;
	out << "\tEditura: " << nume_editura << std::endl;
	out << "Numar Volume: " << nr_volume << std::endl;
	out << "\tPagini volume: " << nr_volume << std::endl;
	for (int i = 0; i < nr_volume; i++)
	{
		std::cout << "\t\t" << i << ": " << nr_pagini_vol[i] << std::endl;
	}
	std::cout << "\tNumar total de pagini: " << Nr_total_pagini() << std::endl;
	try
	{
		std::cout << "\tMedie pagini: " << Medie_pagini() << std::endl;
	}
	catch (std::runtime_error& err_calcul)
	{
		std::cout << "Eroare in calcul" << std::endl;
		std::cerr << err_calcul.what() << std::endl;
	}
	out << "\tFormat: " << format<std::string>(Medie_pagini()) << std::endl;
}

void c_n_fictiune::afisare(std::ostream& out) const
{
	carte::afisare(out);
	out << "Carte: " << nume_carte << std::endl;
	out << "\tAutor: " << nume_autor << std::endl;
	out << "\tEditura: " << nume_editura << std::endl;
	out << "\tNumar pagini: " << nr_pagini << std::endl;
}