#include <stdio.h>

void preBmBc(char* str, int substrl, int* d) {
	int i;
	for (i = 0; i < 256; ++i) {
		d[i] = substrl;
	}
	for (i = 0; i < substrl - 1; ++i)
		d[str[i]] = substrl - 1-i;
}
 
int strlen(char* str) {
	int i = 0;
	for (i = 0; str[i] != '\n'; i++);
	return i;
}

void boyerMoore(char* str, char* substr) {
	int substrl = strlen(substr);
	int d[256];
	preBmBc(substr, substrl, d);
	for (int i = 0; i < (1000 - substrl) && str[i] != '\n';) {
		int flag = 1;
		for (int j = 0; substr[j] != '\n'; ++j) {
			if ((str[i + j] != substr[j]) || (i + j > 999)) {
				flag = 0;
				break;
			}
		}	
		if (flag) {
			printf("%d ", i);
		}
		i += d[str[i + substrl - 1]];
	}
}

int main() {
	printf("Vvedite stroku: ");
	char str[1000];
	fgets(str, 1000, stdin);
	printf("Vasha stroka: %s\n", str);
	printf("Vvedite podstroku:");
	char substr[1000];
	fgets(substr, 1000, stdin);
	printf("Vasha podstroka: %s\n", substr);
	boyerMoore(str, substr);
	return 0;
}
