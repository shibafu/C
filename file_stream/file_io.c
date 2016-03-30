#include"including.h"

typedef struct
{
  void (*open)(FILE **fp);
  void (*read)(void **buf, char *kata, int size, FILE **fp);
  void (*write)(void *buf, int size, int n, FILE **fp);
  void (*close)(FILE **fp);

}fpControl;


/*
  fpControl’¤Î’´Ø’¿ô
  ’¤Õ’¤¡’¤¤’¤ë’¤Ý’¤¤’¤ó’¤¿ ’¤ò’³«’¤¯
*/
void fp_open(FILE **fp)
{
  if((*fp = fopen("./data.dat","a+"))==NULL){
      printf("File cannot open!;(\n");
    };
}

/*
  fpControl’¤Î’´Ø’¿ô
  ’¤Õ’¤¡’¤¤’¤ë’¤Ý’¤¤’¤ó’¤¿ ’¤ò’ÆÉ’¤ß’¹þ’¤à
  ’°ú’¿ô void buf ’¤³’¤Ô’¡¼’Àè’¤Ð’¤Ã’¤Õ’¤¡
      char ’¤Ý’¤¤’¤ó’¤¿kata  ’¤Ð’¤Ã’¤Õ’¤¡’¤Î’·¿’Ì¾
      int size ’¤Ð’¤Ã’¤Õ’¤¡’¤Î’¤µ’¤¤’¤º
      FILE fp ’¦Õ’¤ë’¤Ý’¤¤’¤ó’¤¿
*/
void fp_read(void **buf, char *kata, int size, FILE **fp)
{
  fread(*buf,kata,size,*fp);
}

/*
  fpControl’¤Î’´Ø’¿ô
  void *buf’¡¡’¡§’¡¡’½ñ’¤­’¹þ’¤ß’¥Ç’¡¼’¥¿’¤Î’¥Ý’¥¤’¥ó’¥¿
  int size’¡¡’¡§’¡¡’½ñ’¤­’¹þ’¤ß’¥Ç’¡¼’¥¿’¤Î’¥Ð’¥¤’¥È’Ä¹’¤µ
  int n’¡¡’¡§’¡¡’½ñ’¤­’¹þ’¤ß’¥Ç’¡¼’¥¿’¤Î’¿ô
  FILE *fp’¡¡’¡§’¡¡FILE’¥Ý’¥¤’¥ó’¥¿
*/
void fp_write(void *buf, int size, int n, FILE **fp)
{
  fwrite(buf,size,n,*fp);
}

/*
  fpControl’¤Î’´Ø’¿ô
  ’¤Õ’¤¡’¤¤’¤ë’¤Ý’¤¤’¤ó’¤¿ ’¤ò’ÊÄ’¤¸’¤ë
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
  
  char str[] = "’Æü’ËÜ’¤ó’¤´’¤â’¤¸’¤ì’¤Ä’¤ò’¤Ë’¤å’¤¦’¤ê’¤ç’¤¯’¤·’¤Æ’¤ß’¤ë";

  fp_c.write(str,sizeof(char),sizeof(str),&fp);

  printf("%s\n",fp);

  fp_c.close(&fp);

  return 0;

}
