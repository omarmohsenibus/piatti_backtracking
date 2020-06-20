#include "piatti.h"
int main(void) {
	struct piatto piatti[] = {
		{SECONDO,   200, "Pollo alle mandorle"},
		{PRIMO,     100, "Gnocchi di patate"},
		{CONTORNO,  300, "Broccoli gratinati"},
		{PRIMO,     200, "Lasagne alla bolognese"},
		{SECONDO,   300, "Parmigiana di melanzane"},
		{CONTORNO,  300, "Sformato di verdure"},
	};
	size_t n = 6;
	char *tipologie[] = {
		"PRIMO",
		"SECONDO",
		"CONTORNO"
	};

	printf("Piatti che Maria puo cucinare per la sua famiglia:\n\n");
	for (size_t i = 0; i < n; i++) 
		printf("{ Nome: %s\tTipologia: %s\tKcal: %d }\n", piatti[i].nome, tipologie[piatti[i].tipologia - 1], piatti[i].Kcal);


	printf("\n");

	makeMenu(piatti, n);
	return 0;
}

