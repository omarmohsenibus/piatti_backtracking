#include "piatti.h"

void addDish(struct menu *menu_curr, struct piatto *piatti, size_t curr_index, bool *piatti_usati) {
	size_t i = menu_curr->n_elementi;
	menu_curr->sol[i] = curr_index;
	menu_curr->n_elementi++;
	menu_curr->Kcal += piatti[curr_index].Kcal;
	piatti_usati[curr_index] = true;
}

void deleteDish(struct menu *menu_curr, struct piatto *piatti, size_t curr_index, bool *piatti_usati) {
	menu_curr->n_elementi--;
	menu_curr->Kcal -= piatti[curr_index].Kcal;
	piatti_usati[curr_index] = false;
}

bool canAddDish(struct menu *menu_curr, struct piatto *piatti, size_t curr_index, int soglia) {
	int conta_Kcal = menu_curr->Kcal;
	if (soglia - conta_Kcal >= piatti[curr_index].Kcal) {
		return true;
	}

	return false;
}

void printSolution(struct piatto *piatti, struct menu *menu_curr, size_t *nsol) {
	printf("Menu_%d\n", *nsol);
	for (size_t i = 0; i < menu_curr->n_elementi; i++) {
		size_t index = menu_curr->sol[i];
		printf("\tNome: %s;\tTipologia: %d;\tKcal: %d;\n", piatti[index].nome, piatti[index].tipologia, piatti[index].Kcal);
	}
}

void setEnviroment(struct menu *menu_curr, bool **piatti_usati, size_t elementi_soluzione, size_t n_piatti) {
	menu_curr->Kcal = 0;
	menu_curr->n_elementi = 0;
	menu_curr->sol = malloc(elementi_soluzione * sizeof(size_t));

	*piatti_usati = calloc(n_piatti, sizeof(bool));
}

void unsetEnviroment(struct menu *menu_curr, bool *piatti_usati) {
	free(menu_curr->sol);
	free(piatti_usati);
}

void backtrack(int i, struct piatto *piatti, size_t n_piatti, struct menu *menu_curr, bool *piatti_usati, int soglia, size_t elementi_soluzione, size_t *nsol) {
	if (i == elementi_soluzione + 1) {
		if (menu_curr->Kcal == soglia) {
			(*nsol)++;
			printSolution(piatti, menu_curr, nsol);
			return;
		}
	}
	for (size_t j = 0; j < n_piatti; j++) {
		if (piatti_usati[j] == false) {
			if (piatti[j].tipologia == i) {
				if (canAddDish(menu_curr, piatti, j, soglia)) {
					addDish(menu_curr, piatti, j, piatti_usati);
					backtrack(i + 1, piatti, n_piatti, menu_curr, piatti_usati, soglia, elementi_soluzione, nsol);
					deleteDish(menu_curr, piatti, j, piatti_usati);
				}
				else {
					backtrack(elementi_soluzione + 1, piatti, n_piatti, menu_curr, piatti_usati, soglia, elementi_soluzione, nsol);
				}
			}
		}
	}
}

void makeMenu(struct piatto *piatti, size_t n_piatti) {
	struct menu menu_curr;
	size_t elementi_soluzione = 3;
	size_t nsol = 0;
	int soglia = 700; //kcal
	bool *piatti_usati = NULL;

	setEnviroment(&menu_curr, &piatti_usati, elementi_soluzione, n_piatti);

	backtrack(1, piatti, n_piatti, &menu_curr, piatti_usati, soglia, elementi_soluzione, &nsol);

	unsetEnviroment(&menu_curr, piatti_usati);

}