#define _CRT_SECUFE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct note {
	char a[64];
	int b;
	char*c;
}note;
void my_copy(note*from, note*to) {
	*to = *from;
	//memcpy(to,from,sizeof(note));//和上述操作等效
	while ((to->c = (char*)malloc(64 * sizeof(char))) == NULL)
		exit(1);
	strcpy(to->c, from->c);
}
int main() {
	note d, e;
	strcpy(d.a, "123");
	d.b = 456;
	while ((d.c = (char*)malloc(64 * sizeof(char))) == NULL)
		exit(1);
	strcpy(d.c, "789");
	printf("d的值为：\n");
	printf("%s\n%d\n%s\n", d.a, d.b, d.c);
	my_copy(&d, &e);
	printf("e的值为：\n");
	printf("%s\n%d\n%s\n", e.a, e.b, e.c);
	if (d.c != NULL) {
		free(d.c);
		d.c = NULL;
	}
	if (e.c != NULL) {
		free(e.c);
		e.c = NULL;
	}
	return 0;
}
