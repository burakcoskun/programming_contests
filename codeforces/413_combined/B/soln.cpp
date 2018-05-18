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

#define maxn 200005

int n,m,in[6];
vector<int> ts[6];
int p[maxn],a[maxn],b[maxn];
const int inf = 1e9+1;

int check(int pos,int &res){
    if(in[pos] < ts[pos].size() && ts[pos][in[pos]] < res){
	res = ts[pos][in[pos]];
	return pos+1;
    }
    return 0;
}

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n; ++i)
	cin >> p[i];
    for(int i = 0 ; i < n; ++i)
	cin >> a[i];
    for(int i = 0 ; i < n; ++i)
	cin >> b[i];

    for(int i = 0 ; i < n; ++i){
	if(a[i] == b[i])
	    ts[a[i]-1].push_back(p[i]);
	else
	    ts[a[i]+b[i]].pb(p[i]);
    }

    for(int i = 0 ; i < 6; ++i)
	sort(ts[i].begin(),ts[i].end());

    cin >> m;
    int c;
    for(int i = 0 ; i < m ; ++i){
	cin >> c;
	int res = inf,pos=-1;
	if(c == 1){
	    //cout << res << " " << in[0] << " " << ts[0].size() << " " << pos  << endl;
	    if(check(0,res))
		pos = 0 ;
	    if(check(3,res))
		pos = 3;
	    if(check(4,res))
		pos = 4;
//	    cout << res << " " << in[0] << " " << ts[0].size() << " " << pos  << endl;
	}
	if(c == 2){
	    if(check(1,res))
		pos = 1 ;
	    if(check(3,res))
		pos = 3;
	    if(check(5,res))
		pos = 5;
	}
	if(c == 3){
	    if(check(2,res))
		pos = 2 ;
	    if(check(4,res))
		pos = 4;
	    if(check(5,res))
		pos = 5;
	}
	if(pos == -1 )
	    cout << "-1 ";
	else{
	    cout << ts[pos][in[pos]] << " ";
	    in[pos]++;
	}
    }
    cout << endl;
}

int main(){
    read_input();
    return 0;
}
