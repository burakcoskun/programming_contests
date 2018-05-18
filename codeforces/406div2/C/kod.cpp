#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int visit[2][7005],round;
int dp[2][7005],n;
int k[2],s[2][7005];

void read_input(){
    scanf(" %d",&n);
    scanf(" %d",&k[0]);
    for(int i=0;i<k[0];++i)
	scanf(" %d",&s[0][i]);
    scanf(" %d",&k[1]);
    for(int i=0;i<k[1];++i)
	scanf(" %d",&s[1][i]);

    for(int i=0;i<n;++i)
	dp[0][i]=dp[1][i] =2;

    dp[0][0] = dp[0][1] = -1;

    for(int i =1 ; i <n;++i){

	bool check = false;
	for(int p = 0; p < 2; ++p){
	    for(int j = 0; j < k[p] ; ++j){
		if(dp[1-p][(i+s[p][j])%n] == -1){
		    dp[p][i] = 1;
		    break;
		}
		else if(dp[1-p][(i+s[p][j])%n] != 1)
		    check = true;
	    }
	    if(dp[p][i] != 1 && check == false)
		dp[p][i] = -1;
	}
    }

    for(int i=1;i<n;++i){
	if(dp[0][i] == 1)
	    printf("Win ");
	else if(dp[0][i] == 2)
	    printf("Loop ");
	else if(dp[0][i] == -1)
	    printf("Lose ");
    }
    printf("\n");
    for(int i=1;i<n;++i){
	if(dp[1][i] == 1)
	    printf("Win ");
	else if(dp[1][i] == 2)
	    printf("Loop ");
	else if(dp[1][i] == -1)
	    printf("Lose ");
    }
    printf("\n");
}

int main(){
    read_input();
    return 0;
}
