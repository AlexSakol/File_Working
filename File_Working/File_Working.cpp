#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <ctype.h>

void creator() { // write a string in the file
	char str[256];
	puts("Enter a string");
	scanf("%s", str);
	puts("Created string");
	puts(str);
	FILE* fp;
	if ((fp = fopen("f:\\folder\\file.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}
	fflush(stdin);
	fprintf(fp, str);
	fclose(fp);
}

void reader() { // read a string from the file
	puts("Read string");
	char str[256];
	FILE* fp;
	if ((fp = fopen("f:\\folder\\file.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fflush(stdin);
	while (fgets(str, 256, fp) != NULL) {
		printf("%s", str);
	}
	fclose(fp);
	printf("\n");
}

void encoder() { // add "la" after even vowel char
	char str[256];
	char str1[256];
	FILE* fp;
	if ((fp = fopen("f:\\folder\\file.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fflush(stdin);
	fgets(str, 256, fp);
	fclose(fp);
	int j = 0;
	for (int i = 0; i < strlen(str); i++, j++) {
		*(str1 + j) = *(str + i);
		if (strcspn(str + i, "aeiouy") == 0)
		{
			str1[++j] = 'l';
			str1[++j] = 'a';
		}
	}
	str1[j] = '\0';
	if ((fp = fopen("f:\\folder\\file.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}
	fflush(stdin);
	fprintf(fp, str1);
	fclose(fp);
	puts("Read encode string");
	if ((fp = fopen("f:\\folder\\file.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fflush(stdin);
	while (fgets(str, 256, fp) != NULL) {
		printf("%s", str);
	}
	fclose(fp);
	printf("\n");
}

void decoder() { // remove "la"
	char str[256];
	FILE* fp;
	if ((fp = fopen("f:\\folder\\file.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fflush(stdin);
	fgets(str, 256, fp);
	fclose(fp);
	int i, j = 0;
	for (i = 0; i < strlen(str); ++i)
	{
		if (str[i] != 'l') { str[j++] = str[i]; }
		else if (str[++i] == 'a') { str[j++] = str[++i]; }
	}
	str[j] = '\0';
	if ((fp = fopen("f:\\folder\\file.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
	}
	fflush(stdin);
	fprintf(fp, str);
	fclose(fp);
	if ((fp = fopen("f:\\folder\\file.txt", "r")) == NULL) {
		printf("Cannot open file.\n"); exit(1);
	}
	fflush(stdin);
	while (fgets(str, 256, fp) != NULL) {
		printf("%s", str);
	}
	fclose(fp);
	printf("\n");
}

void main() {
	int s = 1;
	int w;
	for (s; s > 0 && s < 5; s = w) {
		puts("1. Create a string and input it to file");
		puts("2. Read created string and print it");
		puts("3. Encode the string and input it to a file");
		puts("4. Decode the string and input it to a file");
		puts("5. Exit");
		puts("Select an option");
		scanf("%d", &w);
		switch (w) {
		case 1:
			creator();
			break;
		case 2:
			reader();
			break;
		case 3:
			encoder();
			break;
		case 4:
			decoder();
			break;
		}
	}
}
