#pragma once
#include "Tema_2.h"

class editura
{
private:
	std::string nume_editura;
public:
	editura(std::string nume_editura);
	editura(editura& cc);
	~editura();
	editura& operator=(const editura& eop);
	friend std::ostream& operator<<(std::ostream& out, const editura& editura);
	void afisare();
};