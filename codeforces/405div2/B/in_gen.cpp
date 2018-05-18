#include<cstdio>

int main(){

    printf("150000 150000\n");
    for(int i=0;i<150000;i+=3){
	printf("%d %d\n",i+1,i+2);
	printf("%d %d\n",i+2,i+3);
	printf("%d %d\n",i+3,i+1);
    }
    return 0;
}
