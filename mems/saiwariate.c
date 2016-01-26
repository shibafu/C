#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void malloc_mems(void **ptr)
{

  if((*ptr = (void *)malloc(50)) == NULL){
    printf("malloc時にメモリが確保できません");
    exit(0);
  };
  
}

void realloc_mems(void **ptr){

  void *tmp;
  //realloc再割当ては一時ヒープを割り当ててから本ポインタに代入する
  if((tmp = (void *)realloc(*ptr,200)) == NULL){
    printf("メモリの再確保に失敗しました");
    exit(0);
  }else{
    *ptr = tmp;
  }
}


int main(void)
{
  char *ptr;
  char *tmp;

  //malloc割り当て
  malloc_mems(&ptr);

  ptr = (char *)ptr;
  scanf("%s",ptr);

  //文字列代入後再割当て
  ptr = (void *)ptr;
  realloc_mems(&ptr);
  ptr = (char *)ptr;

  printf("%s\n",ptr);
  printf("割り当てられたアドレスは%p\n",&ptr);
  free(ptr);

  return 0;
}

