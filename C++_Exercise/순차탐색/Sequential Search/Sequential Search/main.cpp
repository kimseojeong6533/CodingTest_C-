#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100

char **array;
int founded;

int main(void) {

	int n;
	char *word;
	word = (char*)malloc(sizeof(char)*LENGTH);
	scanf_s("%d %s", &n, word);
	array = (char**)malloc(sizeof(char*)*n);
	for (int i = 0; i < n; i++)
	{
		array[i] = (char*)malloc(sizeof(char)*LENGTH);
		scanf_s("%s", array[i]);
	}

	for (int i = 0; i < n; i++) {
		if (!strcmp(word, array[i]))
		{
			printf("%d��° �����Դϴ�", i + 1);
			founded = 1;
		}
	}
	if (founded != 1) printf("���Ҹ� ã�� �� �����ϴ�\n");


	system("pause");
	return 0;
}