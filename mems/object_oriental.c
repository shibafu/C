#include<stdio.h>
#include<stdlib.h>

/*** 標準入出力オブジェクト
 *  3つの関数が入っている
 */
typedef struct{
  void ( *malloc_one)();
  void ( *scanf_alter)();
  void ( *print_one)();
}IOs_obj;
/*** プロトタイプ宣言 ***/

/* メモリ構造体関数 */
//メモリの確保
void malloc_one (void **mem_p, int charnum);

/***  ***/
//数列の生成
int* integ_array(int *int_array);
//文字の入力
void scanf_alter(char **input);

//標準入出力構造体実体化
IOs_obj* IOs_obj_mems(IOs_obj *i);

//文字の出力
void print_one(char *output);
void print_onepara(char *output, int param);
void print_one_Arraypara(char *output, int Array[]);

#define INPUTARRAY 30

/* メイン関数 */
int main(int argc, char **argv){
  char *input;
  char *inp_debug;
  int Array[30];
  
  //フラッシュ用
  int c;

  //構造体実体化
  IOs_obj *is;
  is = IOs_obj_mems(is);

  (*is).malloc_one((void **)&input, INPUTARRAY);
  (*is).scanf_alter(&input);
  (*is).print_one(input);

  while((c = getchar() )!= EOF){
    if(c == '\n'){
      break;
    }
  };

  scanf("%10s",inp_debug);
  printf("%s\n",inp_debug);

}

IOs_obj* IOs_obj_mems(IOs_obj *i){
  i->malloc_one = malloc_one;
  i->scanf_alter = scanf_alter;
  i->print_one = print_one;

  return i;
}


void print_one(char *output){
  printf("%s\n",output);
}

void scanf_alter(char **input){
  //数字を変換して代入　未実装
  //char scanfoption[30];
  //strcpy(scanfoption,"%[");

  scanf("%[29]",*input);
}


//メモリ確保の実装
void malloc_one(void **mem_p, int charnum){
  *mem_p = (char *)malloc(sizeof(char) * charnum);
  
  if(mem_p == NULL){
    printf("メモリの動的確保に失敗しました\n");
    exit(1);
  }

}
