#pragma once
#include "Tema_1.h"

class carte
{
private:
	std::string nume_carte;
	int nr_volume;
	std::vector<int> nr_pagini_vol;
	std::vector<float> rating_vol;
	int nr_pagini_total;
	float medie_rating,medie_pagini;

public:
	carte(std::string nume_carte, int nr_volume, std::vector<int> nr_pagini_vol, std::vector<float> rating_vol);
	carte(carte& cc);
	~carte();
	carte& operator=(const carte& eop);
	friend std::ostream& operator<<(std::ostream& out, const carte& carte);
	int Nr_total_pagini(int nr_pagini_total);
	float Medie_rating(float medie_rating);
	float Medie_pagini(float medie_pagini, int nr_pagini_total);
	void afisare();
};