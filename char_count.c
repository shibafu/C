#include "including.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ro_maji(char *inpu){

  char output[30];
  int result_inte = 0;

  if( (strcmp("word",inpu)) == 0 ){
    strcpy(output, inpu);
	printf("%s\n",&output);
    result_inte = 1;
  } else {
    strcpy(output, "ナカッタ");
	printf("%s\n",&output);
    result_inte = 0;
  }
  return result_inte;
}

int main(int argc, char argv){
  int i,j;
  char *p_input;

  p_input = (char *)malloc(30 * sizeof(char));

  while(1){

  scanf("%s",p_input);
  printf("入力サレマシタ\n");  

  int flag1 = ro_maji(p_input);
  printf("%d\n",flag1);


  fflush(stdin);

  }

  free(p_input);

  return 0;
}


