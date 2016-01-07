#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MEM_SPACE 10

int main(int argc,char **argv)
{
  //ポインタッタ
  char *inputp = NULL;
  char input = '\0';
  inputp = (char *)malloc(MEM_SPACE);
  FILE *fp;
  int boolean = 0;

  printf("ぽいんっ立った\n");
  inputp = fgets(inputp,11,stdin);
  
  printf("%s\n",inputp);


  int i;
  //for(i=1;i<11;i++){
    if( inputp[strlen(inputp) -1] != '\n'){
      while(getchar() != '\n' );
    }
    //}
}

