#include<stdio.h>
#include<stdlib.h>

#include<D2D1.h>
#include<direct.h>

struct Student{
	char name[30];
	char age[30];
};

void sf(char *input){
	scanf("%s",input);
}

void pf(char *input){
	printf("%s\n",input);
}


int main(int argc, char **argv){
	int i;
	char input[40];

	struct Student *st;

	st = (Student *)malloc(sizeof(Student)*10);

	sf(st[2].name);
	pf(st[2].name);

	free(st);

	return 0;
}