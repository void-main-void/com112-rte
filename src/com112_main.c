#include <stdio.h>

int menu();
int relatorio();

int main(int argc, char const *argv[]) {
	menu();
	return 0;
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