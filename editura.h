#pragma once
#include <iostream>

class editura
{
private:
	std::string nume_editura = "";
public:
	editura() = default;
	//editura(std::string nume_editura);
	editura(editura& cc);
	~editura();
	editura& operator=(const editura& eop);
	friend std::ostream& operator<<(std::ostream& out, const editura& editura);
	friend std::istream& operator>>(std::istream& in, editura& editura);
	void afisare();
};