#include<cstdio>
#include<cstdlib>

using namespace std;

int ar[200005];

int n,q;

long long int res = 0 ;

int find(int left,int right, int val){
    int mid;

    while(left < right){
	int mid = (left+right)/2;
	if(ar[mid] < val)
	    left = mid + 1;
	else
	    right = mid -1;
    }

    if(ar[left] > val)
	left --;
    return left;
}

int main(){

    scanf(" %d %d",&n,&q);
    for(int i=1; i<=n; ++i)
	ar[i] = i;

    int a,b;
    for(int i = 0 ; i < q; ++i){
	scanf(" %d %d",&a,&b);
	int temp = ar[a];
	ar[a] = ar[b];
	ar[b] = temp;

	int p = find(a+1,b,ar[a]);
	res += p - a;
	res -= b - p;

	p = find(a,b-1,ar[b]);
	res -= b - p;
	res += p - a;
/*
	if(a > b){
	    if(ar[a] > ar[b])
		res++;
	    else
		res --;
	}
	if(a < b){
	    if(ar[a] < ar[b])
		res--;
	    else 
		res++;
	}
*/
	printf("%lld\n",res);
    }
    return 0;
}
