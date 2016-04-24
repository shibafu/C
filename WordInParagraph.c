#include<stdio.h>
#include<string>
#include<stdlib.h>

#define SEARCH "count"

char *word_in_para(char paragraph[],char search[])
{
	char *L_return_p;

	L_return_p = strstr(paragraph,search);

	if(L_return_p != NULL){
		printf("Gotcha\n!");
	}else{
		printf(";)");
	}


	return L_return_p;
}


int main(int args, char *argv[])
{
	char input[40];
	char *searched;
	char quit;
	int i,j;


	scanf("%39s%*[^\n]",input);

	printf("入力されました\n");

	printf("%s\n",input);

	searched = word_in_para(input,SEARCH);

	printf("%d\n",searched-input+1);

	fflush(stdin);
	while((quit = getchar() )!= EOF){
		
		printf("qを押して終了してください\n");
		
		if(quit == 'q'){
			break;
		}else if(quit == 'Q'){
			break;
		}

	}

	return 0;
}