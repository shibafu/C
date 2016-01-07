#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MEMORYBYTE 50

//ポインタを参照渡しで受け取って代入するので2重ポインタ
void mallocKakuho(char **pointer, int Membyte);
//代入はしないのでポインタでOK
void mallocFree(char *pointer);
void fflushKarayomi(char *pointer);

//char *str;

int main(int argc, char **argv){

     //メモリ確保領域、関数崎でポインタ変数の参照渡しをするため二重ポインタ
     char *str;

     if(str == NULL){
	  printf("ガッ\n");
     }

     mallocKakuho(&str,MEMORYBYTE);
     //str = (char *)malloc(MEMORYBYTE * sizeof(char));

     fgets(str,MEMORYBYTE,stdin);

     printf("%s\n",str);

     mallocFree(str);
     fflushKarayomi(stdin);

}

//ヌル文字を含む文字列にのみ対応
void fflushKarayomi(char *pointer){

     if(pointer[strlen(pointer)-1] == '\n'){
	  while(getchar() != '\n');
     }
}

void mallocFree(char *pointer)
{
     free(pointer);
}

void mallocKakuho(char **pointer,int Membyte){

     printf ("before malloc : %p\n", pointer);

     *pointer = (char *)malloc(Membyte);
     if(pointer == NULL){
	  printf("メモリが確保で着ませんでした\n");
	  exit(EXIT_FAILURE);
     }

     printf ("after malloc : %p\n", pointer);

     //return pointer;
}
