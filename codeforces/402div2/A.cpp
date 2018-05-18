#include<cstdio>
#include<cstdlib>

using namespace std;

int ar1[6],ar2[6],n;

int main(){
    scanf(" %d",&n);
    int a;
    for(int i=0;i<n;++i){
	scanf(" %d",&a);
	ar1[a] ++; 
    }
    for(int i=0;i<n;++i){
	scanf(" %d",&a);
	ar2[a] ++; 
    }
    for(int i=1;i<6;++i)
	if((ar1[i]+ar2[i]) % 2){
	    printf("-1\n");
	    return 0;
	}
    int res = 0;
    for(int i=1 ; i < 6; ++i){
	res += (abs(ar1[i]-ar2[i]))/2;
    }
    printf("%d\n",res/2);
    return 0;
}
