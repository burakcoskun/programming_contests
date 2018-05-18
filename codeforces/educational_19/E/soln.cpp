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

int dp[2005][1005][2];
int n,k;
string s;

int solve(int d ,int p){

   // cout << d << " " << p << endl;
   //
   if(p < n && abs(d-1000) == k)
       return -1;

    if(dp[d][p][0])
	return dp[d][p][0];

    if(p == n){
	if(abs(d - 1000) == k)
	    return 1;
	return -1;
    }

    if(s[p] == 'W')
	return dp[d][p][0] = solve(d+1,p+1);
    else if(s[p] == 'L')
	return dp[d][p][0] = solve(d-1,p+1);
    else if(s[p] == 'D')
	return dp[d][p][0] = solve(d,p+1);

    int res = -1;
    if(res < solve(d+1,p+1)){
	dp[d][p][1] = 1;
	return dp[d][p][0] = solve(d+1,p+1);
    }
    if(res < solve(d-1,p+1)){
	dp[d][p][1] = 2;
	return dp[d][p][0] = solve(d-1,p+1);
    }
    if(res < solve(d,p+1)){
	dp[d][p][1] = 3;
	return dp[d][p][0] = solve(d,p+1);
    }
    return dp[d][p][0] = -1;
}

void read_input(){
    cin >> n >> k >> s;

    if(solve(1000,0) == 1){
	int d = 1000;
	for(int i = 0 ; i < n ; ++i){
	    if(dp[d][i][1] == 1 || s[i] == 'W'){
		d++;
		cout << 'W';
	    }
	    else if(dp[d][i][1] == 2 || s[i] =='L'){
		--d;
		cout << "L";
	    }
	    else
		cout <<"D";
	}
	cout << endl;
    }
    else
	cout << "NO" << endl;
}

int main(){
    read_input();
    return 0;
}
