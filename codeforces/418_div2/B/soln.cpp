#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
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
#define fs first
#define sc second

int n,a[1005],b[1005],c[1005],used[1005];

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n; ++i)
	cin >> a[i];
    for(int i = 0 ; i < n ; ++i)
	cin >> b[i];

    for(int i = 0 ; i < n; ++i){
	memset(used, 0 , sizeof used);
	for(int j = 0 ; j < n; ++j)
	    if( j != i ){
		c[j] = a[j];
		used[a[j]] = 1;
	    }
	int cnt = 0 ;
	for(int j = 1 ; j <= n; ++j)
	    if(!used[j]){
		c[i] = j;
		++cnt;
	    }
//	printf("%d\n",cnt);
	if(cnt != 1) 
	    continue;

	cnt = 0 ;
	for(int j = 0 ; j < n ; ++j)
	    if(c[j] != b[j])
		++cnt;

	if(cnt == 1){
	    for(int j = 0 ; j < n ; ++j)
		cout << c[j] << " " ;
	    cout << endl;
	    break;
	}
    }
}

int main(){
    read_input();
    return 0;
}
