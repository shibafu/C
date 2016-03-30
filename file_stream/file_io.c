#include"including.h"

typedef struct
{
  void (*open)(FILE **fp);
  void (*read)(void **buf, char *kata, int size, FILE **fp);
  void (*write)(void *buf, int size, int n, FILE **fp);
  void (*close)(FILE **fp);

}fpControl;


/*
  fpControl��Β�ؒ��
  ��Ւ�������뒤ݒ����󒤿 ��򒳫���
*/
void fp_open(FILE **fp)
{
  if((*fp = fopen("./data.dat","a+"))==NULL){
      printf("File cannot open!;(\n");
    };
}

/*
  fpControl��Β�ؒ��
  ��Ւ�������뒤ݒ����󒤿 ����ɒ�ߒ�����
  ������ void buf �����Ԓ����蒤В�Ò�Ւ��
      char ��ݒ����󒤿kata  ��В�Ò�Ւ����Β���̾
      int size ��В�Ò�Ւ����Β��������
      FILE fp ��Ւ�뒤ݒ����󒤿
*/
void fp_read(void **buf, char *kata, int size, FILE **fp)
{
  fread(*buf,kata,size,*fp);
}

/*
  fpControl��Β�ؒ��
  void *buf�����������񒤭�����ߒ�ǒ�������Β�ݒ����󒥿
  int size�����������񒤭�����ߒ�ǒ�������Β�В����ȒĹ���
  int n�����������񒤭�����ߒ�ǒ�������Β��
  FILE *fp���������FILE��ݒ����󒥿
*/
void fp_write(void *buf, int size, int n, FILE **fp)
{
  fwrite(buf,size,n,*fp);
}

/*
  fpControl��Β�ؒ��
  ��Ւ�������뒤ݒ����󒤿 ����Ē�����
*/
void fp_close(FILE **fp)
{
  if((fclose(*fp))==NULL){
      printf("File cannot close!;(\n");
    };
}

void fpc_objectivation(fpControl *fpc){
  fpc->open = fp_open;
  fpc->read = fp_read;
  fpc->write = fp_write;
  fpc->close = fp_close;
  
}

int main(){

  FILE *fp;
  fpControl fp_c;

  fpc_objectivation(&fp_c);

  fp_c.open(&fp);
  
  char str[] = "�����ܒ�󒤴��⒤���쒤Ē��˒�咤���꒤璤������ƒ�ߒ��";

  fp_c.write(str,sizeof(char),sizeof(str),&fp);

  printf("%s\n",fp);

  fp_c.close(&fp);

  return 0;

}
