#include "piatti.h"
int main(void) {
	struct piatto piatti[] = {
		{PRIMO,     100, "Gnocchi di patate"},
		{PRIMO,     200, "Lasagne alla bolognese"},
		{CONTORNO,  300, "Sformato di verdure"},
		{CONTORNO,  300, "Broccoli gratinati"},
		{SECONDO,   300, "Parmigiana di melanzane"},
		{SECONDO,   200, "Pollo alle mandorle"},
	};
	size_t n = 6;

	printf("Piatti che Maria puo cucinare per la sua famiglia:\n\n");
	for (size_t i = 0; i < n; i++) {
		printf("{ Nome: %s\tTipologia: %d\tKcal: %d }\n", piatti[i].nome, piatti[i].tipologia, piatti[i].Kcal);
	}

	printf("\n");

	makeMenu(piatti, n);
	return 0;
}

