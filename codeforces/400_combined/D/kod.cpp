#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,m;
vector<bool> in;
vector< vector<int> > toggle;
vector<int> color(100001);
vector< vector<pair<int,int> > > edges(100001);

void read_input(){
    cin >> n >> m;
    int a;
    for(int i = 0 ; i < n; ++i){
	cin >> a;
	in.push_back(a);
    }

    toggle.resize(n);
    for(int i = 0 ; i < m; ++i){
	int x,a;
	cin >> x;
	for(int j = 0 ; j < x; ++j){
	    cin >> a;
	    --a;
	    toggle[a].push_back(i);
	}
    }

    for(int i = 0 ; i < n; ++i){
	edges[toggle[i][0]].push_back(make_pair(toggle[i][1],in[i]));
	edges[toggle[i][1]].push_back(make_pair(toggle[i][0],in[i]));
    }
}

int calc(int node,int c){
//    cout << node << " " << c <<" " << edges[node].size() <<"\n";
    if(color[node])
	return color[node] == c;
    color[node] = c;

    for(int i = 0 ; i < edges[node].size() ; ++i){
	int nc;
	if(edges[node][i].second == 1)
	    nc = c;
	else
	    nc = 3-c;
	if(calc(edges[node][i].first,nc) == 0)
	    return 0;
    }
    return 1;
}

int main(){
    read_input();
    bool check = false;
//    cout << m<<endl;
    for(int i = 0 ; i  < m ; ++i)
	if(!color[i] && !calc(i,1)){
	    cout << "NO\n";
	    check = true;
	    break;
	}
    if(!check)
	cout << "YES\n";
    return 0;
}
