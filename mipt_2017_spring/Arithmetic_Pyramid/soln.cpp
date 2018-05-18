#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

long long n,v,a,b,c,m,q;

int p[4005][4005];
int spt[4005][4005][13];


void calc(){
    p[0][0] = v;
    for(int i = 1; i < n; ++i)
	p[i][0] = (p[i-1][0]*c)%m;
    for(int i = 1 ; i < n; ++i)
	for(int j = 1; j <= i; ++j)
	    p[i][j] = (a*p[i][j-1]+b*p[i-1][j-1])%m;
    for(int i = 0 ; i < n ;++i)
	for(int j=0; j<=i; ++j)
	    spt[i][j][0] = p[i][j];

    for(int i = 0 ; i < n - 1; ++i)
	for(int  j = 0 ; j <= i ; ++j){
	    spt[i][j][1] = max(spt[i][j][0],spt[i+1][j][0]);
	    spt[i][j][1] = max(spt[i][j][1],spt[i+1][j+1][0]);
	}


    for(int k = 2 ; (1 << k)  <= n; ++k)
	for(int i = 0 ; i < n; ++i)
	    for(int j = 0 ; j <= i ; ++j)
	    	if(i + (1 << k ) <= n){
		int jump = 1 << (k-1);
		spt[i][j][k] = max(spt[i][j][k-1],spt[i + jump][j][k-1]);
		spt[i][j][k] = max(spt[i][j][k],spt[i+jump][j+jump/2][k-1]);
		spt[i][j][k] = max(spt[i][j][k],spt[i+jump][j+jump][k-1]);
		spt[i][j][k] = max(spt[i][j][k],spt[i+jump/2][j][k-1]);
		spt[i][j][k] = max(spt[i][j][k],spt[i+jump/2][j+jump/2][k-1]);
	    }
}

void read_input(){
    cin >> n >> v >> a >> b >> c >> m ;

    calc();

    cin >> q;

    int r,s,x;
    for(int i = 0 ; i < q; ++i){

	cin >> r >> s >> x; 
	--r; --s;

	int jump = 1, k =0 ;
	while( jump  <= x ){ jump*=2 ; ++k;}
	jump/=2; --k;

	int res = spt[r][s][k];
	if(jump +jump/2 <= x){
	    res = max(res,spt[r+jump/2][s][k]);
	    res = max(res,spt[r+jump/2][s+jump/2][k]);
	}
	int pos = r + x - jump;

	res = max(res,spt[pos][s][k]);
	res = max(res,spt[pos][s + (x-jump)/2][k]);
	res = max(res,spt[pos][s + x-jump][k]);

	cout << res << endl;
    }
}

int main(){
    read_input();
    return 0;
}
