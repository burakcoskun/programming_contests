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

int n,m,k;
vector< pair<int,int> > edges[2005];
int dp[85][85][85];
const int inf = 1e9;

int find(int v,int to,int h){
    if(h == k)
	return 0 ;

    if(dp[v][to][h])
	return dp[v][to][h];

    int a = min(v,to);
    int b = max(v,to);

    int res = inf;

    for(int i = 0; i < edges[v].size(); ++i){
	if(edges[v][i].first <= a || edges[v][i].first >= b)
	    continue;
	int t1,t2;
	t1 = find(edges[v][i].first,to,h+1) + edges[v][i].second;
	t2 = find(edges[v][i].first,v,h+1) + edges[v][i].second;

	res = min(res,t1);
	res = min(res,t2);
    }

    return dp[v][to][h] = res;
}

void read_input(){
    cin >> n >> k >> m;
    for(int i = 0 ; i < m; ++i){
	int a,b,c;
	cin >> a >> b >> c;
	edges[a].pb(mp(b,c));
    }

    int res = inf;
    for(int i = 1 ; i <= n ; ++i){
	res = min(res, find(i,n+1,1));
	res = min(res, find(i,0,1));
    }
    if(res == inf)
	cout << -1 << endl;// find(0,n+1,1);
    else
	cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
