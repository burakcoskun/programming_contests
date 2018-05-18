#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
int g[10005];

void read_input(){
    scanf(" %d %d",&n,&m);
    bool yes = true;
    for(int i = 0; i<m; ++i){
	int k;
	scanf(" %d",&k);
	for(int j = 0 ; j < k; ++j)
	    scanf(" %d",&g[j]);
    	bool check = true;
	for(int a = 0 ; a < k; ++a)
	    for(int b = a + 1; b<k;++b)
		if(g[a]+g[b] == 0){
		    check = false;
		    break;
		}
	if(check){
	    printf("YES\n");
	    yes = false;
	    break;
	}
    }
    if(yes)
	printf("NO\n");
}

int main(){
    read_input();
    return 0;
}
