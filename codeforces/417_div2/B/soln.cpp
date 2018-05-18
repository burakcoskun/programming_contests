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

int n,m,first[20],last[20],dp[20][2];
vector<string> l(105);
const int inf = 1e9;
int zero = 0 ;
int solve(int floor,int pos){
    if(floor <= zero ){
	if(last[floor] == 0)
	    return 0;
	if(pos == 0 )
	    return last[floor];
	else
	    return m+1-first[floor];
    }
    if(dp[floor][pos] != -1)
	return dp[floor][pos];

    int res = m+2+solve(floor-1,1-pos);
    if(last[floor] == 0)
	res = min(res,solve(floor-1,pos)+1);
    else{
	if(pos == 0)
	    res = min(res,last[floor]*2+1+solve(floor-1,pos));
	else
	    res = min(res,(m+1-first[floor])*2+1+solve(floor-1,pos));
    }
    return dp[floor][pos] = res;
}

void read_input(){
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i){
	cin >> l[i];
	for(int j = 0 ; j < m+2;++j)
	    if(l[i][j] == '1')
		last[i] = j;
	for(int j = m+1; j >=0 ; --j)
	    if(l[i][j] == '1')
		first[i] = j;
    }
    for(int i = 0 ; i < n; ++i){
	if(last[i] == 0)
	    zero = i+1;
	else
	    break;
    }
    memset(dp , -1 , sizeof dp);
    cout << solve(n-1,0) << endl;
}

int main(){
    read_input();
    return 0;
}
