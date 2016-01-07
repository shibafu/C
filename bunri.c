#include<stdio.h>
#include<string.h>

int
 kaijou(input)
     int input;
{
     int i;
     int result = input;
     for(i = input;i>0;--i){
	  result = result *i;
	  printf("%d\n",result);
        }
     return result;
}


int main(int argc, char **argv){
     int moto = 14;
     int result;
     result = kaijou(moto);

     printf("%d\n",result);
     return 0;
}
