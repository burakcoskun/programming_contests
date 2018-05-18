#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<map>
#include<cstring>
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

int dp[5005],a[5005],n,last[5005],first[5005];
bool ds[5005][5005];

int solve(int pos){
    if(pos == n)
	return 0;

    if(dp[pos] != -1)
	return dp[pos];

    int res = solve(pos+1);

    int sum = 0 ;
    int minPos = 0 ;
    for(int i = pos; i < n; ){
	int j;
	minPos = max(minPos,last[a[i]]);
	for(j = i ; j <= minPos && j < n; ++j){
	    if(first[a[j]] < pos)
	    	return dp[pos] = res;
	    minPos = max(minPos,last[a[j]]);
	    if(ds[pos][a[j]] == 0)
		sum = sum ^ a[j];
	    ds[pos][a[j]] = 1;
	}

	i = j;
	res = max(res,solve(i)+sum);
    }

    return dp[pos] = res;
}

void read_input(){
    cin >> n; 
    memset(first, -1, sizeof first);
    for(int i = 0 ; i < n; ++i){
	cin >> a[i];
	last[a[i]] = i ;
	if(first[a[i]] == -1)
	    first[a[i]] = i;
    }

    memset(dp, -1 , sizeof dp);
    cout << solve(0) << endl;
}

int main(){
    read_input();
    return 0;
}
