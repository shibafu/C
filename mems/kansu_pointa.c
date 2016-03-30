#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//構造体定義
typedef struct{
  int Number;
  char Hinshi[10];
  char Naiyou[20];
  char Bunsetsu[10];
  int Fromnum;

} WORD;

//void inpuWORD(struct USER);
//void printWORD(struct USER);

typedef struct{
  void (*in_p)();
  void (*pri_p)();
}KansuObject;

void inpuWORD(WORD *wd)
{
  wd->Number = 1;
  strcpy(wd->Hinshi,"名詞");
  strcpy(wd->Naiyou,"腋は性器");
  strcpy(wd->Bunsetsu,"主節");
  wd->Fromnum = 34;

}


void printWORD(WORD *wd)
{
  printf("%d\n",wd->Number);
  printf("%s\n",wd->Hinshi);
  printf("%s\n",wd->Naiyou);
  printf("%s\n",wd->Bunsetsu);
  printf("%d\n",wd->Fromnum);

}



int main(){

  KansuObject KObj_m;
  WORD wor_m;

  wor_m.Number = 0;

  //関数ポインタに代入
  KObj_m.in_p = inpuWORD;
  KObj_m.pri_p= printWORD;

  KObj_m.in_p(&wor_m);
  KObj_m.pri_p(&wor_m);

  return 0;
}
