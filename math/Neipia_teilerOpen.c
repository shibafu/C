#include<stdio.h>
#include<stdlib.h>

#define DEBUGLOOP 20

//指定された階乗数を返す。
//分母に使う
double Kaijou(int topNum){
  double result = 1;
  int i;

  for(i=1;i<topNum+1;i++)
    {
    result = result * i;
    }
  
  printf("%e\n",result);
  return result;
}

int main(int argc, char **argv)
{
  int i;

  //式のループ数　t_loop次近似
  int t_loop;
  //ネイピア数　結果を格納する
  float Neipia = 0.0;
  //分母
  double bunbo_kai;

  if( argv[1] == NULL){
    printf("e ^ xをテイラー展開して求めます\n");
    printf("引数で乗数を選択してくだい\n");
    return 0;
	} else {
    t_loop = atoi(argv[1]);
  }

//メインループ展開の計算

  for(i=0;i<t_loop;i++){
    //階乗に使用する分母を求める
    bunbo_kai = Kaijou(i);
    //メイン式
      if(bunbo_kai != 0){
	Neipia = Neipia + (t_loop ^ i) / bunbo_kai;
      } 
      else
	{//分母が０の時（初項）限定
	  Neipia = Neipia + (t_loop ^ i);
	}
  }

  printf("e^xは %f\n",Neipia);
  return 0;

}
