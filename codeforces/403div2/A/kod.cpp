#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,table[100005],res;

void read_input(){
    scanf(" %d",&n);
    int a,c = 0 ;
    for(int i = 0 ; i < 2*n ; ++i){
	scanf(" %d",&a);
	
	table[a] ++ ;
	if(table[a] % 2)
	    c ++ ;
	else
	    c--;

	res = max(res,c);
    }
    printf("%d\n",res);
}

int main(){
    read_input();
    return 0;
}
