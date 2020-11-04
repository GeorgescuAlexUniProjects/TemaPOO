#include "Tema_1.h"
#include "carte.h"
#include "editura.h"
#include "autor.h"

int main()
{
	carte c("Overlord",12, 288);
	editura e("Yen Press");
	autor a("Kugane Maruyama");
	carte c1 = c;
	carte c2("c", 1, 1);
	c2 = c;
	std::cout << c;
	editura e1 = e;
	editura e2("e");
	e2 = e;
	std::cout << e;
	autor a1 = a;
	autor a2("a");
	a2 = a;
	std::cout << a;
	c.afisare();
	e.afisare();
	a.afisare();
	return 0;
}