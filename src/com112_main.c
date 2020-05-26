#include <stdio.h>

int power(int x, int y);
int menu();
int relatorio();

int main(int argc, char const *argv[]) {
	menu();
	return 0;
}

int power(int x, int y) {
	int power = 1;
	if (x == 0) return 0;
	if (y == 0) return 1;
	while (y-- > 0) {
		power *= x;
	}
	return power;
}

int menu() {
	int op = 0;
	do {
		printf(" 1. Bubble Sort\n");
		printf(" 2. Selection Sort\n");
		printf(" 3. Insertion Sort\n");
		printf(" 4. Relatorio\n");
		printf("-1. Sair\n");
		scanf("%d", &op);

		switch (op) {
			case 1: {
				printf("OP = %d!\n");
			} break;
			case 2: {
				printf("OP = %d!\n");
			} break;
			case 3: {
				printf("OP = %d!\n");
			} break;
			case -1: {
			} break;
			default: {
				op = -1;
			} break;
		}
	} while (op != -1);
}