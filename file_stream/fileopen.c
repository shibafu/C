#include<stdio.h>
#include<stdlib.h>

int main()
{

  FILE *fp;

  if((fp = fopen("./file.txt","a")) == NULL)
    {
  printf("ファイルオープンエラー\n");
  exit(EXIT_FAILURE);
    }
  else
    {
  printf("ファイルが作られました\n");
    }



  return 0;
}
