#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define pb push_back
#define mp make_pair

int n,k;
int res[105][105];

void read_input(){
    cin >> n >> k ;

    if(n*n < k){
	cout << -1 << endl;
	return ;
    }

    for(int i=0 ; i < n; ++i)
	for(int j = 0; j < n; ++j)
	{
	    if(res[i][j] == 1)
		continue;
	    if(i!=j && k > 1){
		k-=2;
		res[i][j] = res[j][i] = 1;
	    }
	    else if(i==j && k > 0){
		--k;
		res[i][j] = 1 ;
	    }

	    if(k == 0)
		break;
	}

    for(int i = 0 ; i < n; ++i,cout << endl)
	for(int j = 0 ; j <  n; ++j)
	    cout << res[i][j] << " ";
}

int main(){
    read_input();
    return 0;
}
