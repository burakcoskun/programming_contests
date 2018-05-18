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
#define fs first
#define sc second

int n,m,c;
int color[300005];
vector<int> ic[300005],e[300005];
vector<pair<int,int> > s;
const int inf = 1e9;

void dfs(int node,int c){
    if(c == 1)
	color[node] = 2;
    else
	color[node] = 1;
    for(int i = 0; i < e[node].size(); ++i)
	if(color[e[node][i]] != inf)
	    dfs(e[node][i],1-c);
}

void read_input(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
	color[i] = inf;
    for(int i = 0 ; i < n ; ++i){
	int k;
	cin >> k;
	s.clear();
	for(int j = 0 ; j < k; ++j){
	    int v ;
	    cin >> v;
	    --v;
	    ic[i].pb(v);
//	    s.pb(mp(color[v],v));
	}
//	sort(s.begin(),s.end());
/*
*/
    }

    for(int i = 0 ; i < n - 1 ;++i){
	int u,v;
	cin >> u >> v;
	--u; --v;
	e[u].pb(v);
	e[v].pb(u);
    }
    dfs(0,0);

    for(int i = 0 ; i < n; ++i){
	s.clear();
	for(int j = 0 ; j < ic[i].size();++j)
	    s.pb(mp(color[ic[i][j]],ic[i][j]));

	sort(s.begin(),s.end());
	int current = 1, t = 0;
	for(int j = 0 ; j < ic[i].size() ;++j){
	    while(t < j && current >= color[s[t].sc]){
		++current;
		++t;
	    }
	    if(color[s[j].sc] == inf || color[s[j].sc] < current)
		color[s[j].sc] = current;
	}
    }

    int res = 0 ;
    for(int i = 0 ; i < m ; ++i)
	res = max(res,color[i]);

    cout << res << endl;

    for(int i = 0 ; i < m ; ++i){
	if(color[i] == inf)
	    cout << "1 ";
	else
	    cout << color[i] << " ";
    }
    cout << endl;
}

int main(){
    read_input();
    return 0;
}
