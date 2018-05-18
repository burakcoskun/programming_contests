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

int n,p[100005];
int cur[100005],res;

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
	cur[i] = 1;
    for(int i = 1 ; i < n ; ++i){
	cin >> p[i];
	--p[i];
    }

    while(1){
	bool finish = false;
	for(int i = 0 ; i < n; ++i)
	    finish = finish | cur[i] ;
	if(finish == false)
	    break;

	res += cur[0] % 2;

	cur[0] = 0 ;
	for(int i = 0 ; i < n;++i){
	    cur[ p[i] ] += cur[i]; 
	    cur[i] = 0 ;
	}
	for(int i = 0 ; i < n; ++i)
	    cur[i] %= 2;
    }
    cout << res << endl;

}

int main(){
    read_input();
    return 0;
}
