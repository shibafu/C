#include<stdio.h>

int main(int argc, char **argv){

	int c,n_count,t_count,space_count;

	while ((c = getchar()) != EOF){


		//�T�[�`��
		if(c == '\n'){
			n_count++;
		}else if(c == '\t'){
			t_count++;
		}else if(c == ' '){
			space_count++;
		}else if(c == 'q'){
			break;
		}

		printf("���s = %d �^�u = %d �� = %d\n",n_count,t_count,space_count);

	}

  printf("bye ;)\n");
  
return 0;
}
