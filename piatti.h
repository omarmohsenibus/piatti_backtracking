#if !defined PIATTI_H
#define PIATTI_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct piatto {
	int tipologia;
	int Kcal;
	char nome[100];
};

struct menu {
	size_t n_elementi;
	size_t *sol;
	int Kcal;
};

enum tipologia {
	PRIMO = 1,
	CONTORNO,
	SECONDO
};

extern void makeMenu(struct piatto *piatti, size_t n_piatti);

#endif //PIATTI_H