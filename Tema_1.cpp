#include "Tema_1.h"
#include "carte.h"
#include "editura.h"
#include "autor.h"

int main()
{
	int nr_volume = 4;
	std::vector<int> nr_pagini_vol = { 288 , 241 , 300 , 341 };
	std::vector<float> rating_vol = { 8.5 , 9 , 7.5 , 9.5 };
	carte c("Overlord", nr_volume, nr_pagini_vol, rating_vol);
	editura e("Yen Press");
	autor a("Kugane Maruyama");
	carte c1 = c;
	carte c2("Overlord", nr_volume, nr_pagini_vol, rating_vol);
	c2 = c;
	std::cout << c;
	editura e1 = e;
	editura e2("Yen Press");
	e2 = e;
	std::cout << e;
	autor a1 = a;
	autor a2("Kugane Maruyama");
	a2 = a;
	std::cout << a;
	c.afisare();
	e.afisare();
	a.afisare();
	return 0;
}