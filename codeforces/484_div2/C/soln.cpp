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

int res;
int cnt[200005],st[100005],n;
vector<pair<int,int>> e;

int dfs(int node,int p){
    int res = 0;
    for(int i = st[node] ; i < e.size() && e[i].fs == node ; ++i)
	if(e[i].sc != p){
	    int subres = dfs(e[i].sc, node);
	    cnt[i] = subres;
	    res += subres;
	}
    return res + 1;
}

void read_input(){
    cin >> n;
    if(n%2){
	cout << -1 << endl;
	return;
    }
    for(int i = 0 ; i < n - 1; ++i){
	int a,b;
	cin >> a >> b;
	--a; --b;
	e.pb(mp(a,b));
	e.pb(mp(b,a));
    }
    sort(e.begin(),e.end());

    st[0] = 0 ;
    for(int i = 1; i < e.size() ; ++i)
	if(e[i].fs != e[i-1].fs)
	    st[e[i].fs] = i;
    dfs(0,0);

    for(int i = 0 ; i < e.size() ; ++i)
	if(cnt[i] && !(cnt[i]%2))
	    ++res;
    
    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
