#include <stdio.h>

//составление таблицы смещений
void preBmBc(char* x, int m, int* bmBc) {
	int i;

	for (i = 0; i < 256; ++i)
		bmBc[i] = m;
	for (i = 0; i < m - 1; ++i)
		bmBc[x[i]] = m - i - 1;
}

//функци€ сравнени€ строк
int memcmp(const void* buf1, const void* buf2, int count)
{
	if (!count)
		return(0);

	while (--count && *(char*)buf1 == *(char*)buf2) {
		buf1 = (char*)buf1 + 1;
		buf2 = (char*)buf2 + 1;
	}

	return(*((unsigned char*)buf1) - *((unsigned char*)buf2));
}

//функци€ вы€снени€ длины строки
int strlen(char* str) {
	int i = 0;
	for (i = 0 ; str[i] != '\n'; i++);
	return i;
}

int func(char* str, char* substr) {
	int strl = strlen(str);
	int substrl = strlen(substr);
	int d[256];
	int j=0;
	char c;
	//преинициализаци€
	preBmBc(str, strl, d);
	//собственно, сам алгоритм
	while (j <= substrl - strl) {
		c = substr[j + strl - 1];
		if ((str[strl-1]==c)&&(memcmp(str,substr+j,strl-1)==0))
			return j;
		j += d[c];	
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
	printf("Result: %d",-1* func(str, substr));
	return 0;
}