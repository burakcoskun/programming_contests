#include<cstdio>
#include<cstdlib>

using namespace std;

int n,k;

int main(){
    scanf(" %d %d",&n,&k);
    if(!n){
	printf("0\n");
	return 0;
    }
    int res = 0 ;
    int div = 0 ;
    int d = 0 ;
    while(n){
	if((n%10) == 0 )
	    div++;
	if( div == k)
	    break;
	if((n%10) != 0)
	    res++;

	n/=10;
	d++;
    }
    if(div == k)
	printf("%d\n",res);
    else
	printf("%d\n",d-1);
    return 0;
}
