#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,res = 1;

vector< vector<int> > edges;
vector<int> color;

void dfs(int v,int p,int pp){
    int c = 1;
//    cout << v << " " << p << " " << pp << "\n";
    for(int i = 0 ; i < edges[v].size(); ++i){
	if(color[ edges[v][i] ])
	    continue;
	while(c == p || c ==pp)
	    c++;
	color[edges[v][i]] = c ;
	res = max(res,c);
	dfs(edges[v][i],c,p);
	c++;
    }
}

void read_input(){
    scanf( " %d",&n);

    edges.resize(n);
    color.resize(n);

    int a, b;
    for(int i = 0  ; i < n - 1 ; ++i){
	scanf(" %d %d",&a,&b);
	--a; --b;
	edges[a].push_back(b);
	edges[b].push_back(a);
    }

    color[0] = 1;
    dfs(0,1,0);
    printf("%d\n",res);
    for(int i = 0 ; i < n; ++i){
	printf("%d ",color[i]);
    }
}

int main(){
    read_input();
    return 0;
}
