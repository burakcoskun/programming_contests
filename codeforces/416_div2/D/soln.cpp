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

int n,m, dh = 0 , dv = 0;
string g[105];
int w[4][2] = { {0,1} ,{0,-1},{1,0},{-1,0}};

queue<pair<int,int> > q;
int path[105][105],fx,fy;
vector<pair<int,int> > res;
vector<int > way;

void tell(int k){
    char ch;
    if(k == 0 && dh == 0)
	ch = 'R';
    if(k == 0 && dh == 1)
	ch = 'L';
    if(k == 1 && dh == 0)
	ch = 'L';
    if(k == 1 && dh == 1)
	ch = 'R';

    if(k == 2 && dv == 0)
	ch = 'D';
    if(k == 2 && dv == 1)
	ch = 'U';
    if(k == 3 && dv == 0)
	ch = 'U';
    if(k == 3 && dv == 1)
	ch = 'D';

    cout << ch << endl;
    fflush(stdout);
}

void bfs();

void calc(){
    int px = fx, py =fy;
    res.clear();
    way.clear();
    while(px != 0 || py != 0){
	res.pb(mp(px,py));
	way.pb(path[px][py]);
	int x = px - w[path[px][py]][0];
	int y = py - w[path[px][py]][1];
	px = x;
	py = y;
    }

    int x,y;
    for(int i = res.size() - 1; i >= 0 ; --i ){
	tell(way[i]);
	px = res[i].fs ; py = res[i].sc ; 
	cin >> x >> y ;
	--x ; --y ;
	int cnt = 0;
	if(x != px ){
	    dv = 1;
	    cnt = 1;}
	if(y != py){
	    dh = 1;
	    cnt = 1;
	}

	if( (x == fx && y ==fy) || g[x][y] == '*')
	    return;

	if(cnt){
	    while(!q.empty()) q.pop();
	    q.push(mp(x,y));
	    bfs();
	   // return;
	}
    }
}

void bfs(){
    memset(path, -1 , sizeof path);
    while(!q.empty()){
	int px = q.front().fs;
	int py = q.front().sc;
	q.pop();

	for(int i = 0 ; i < 4 ;++i){
	    int x = px + w[i][0];
	    int y = py + w[i][1];

	    if(x > -1 && y > -1 && x < n && y < m && g[x][y] !='*' && path[x][y] == -1){
		path[x][y] = i;
		q.push(mp(x,y));
		if(g[x][y] == 'F'){
		    calc();
		    return;
		}
	    }
	}
    }
}

void read_input(){
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i){
	cin >> g[i];
	for(int j = 0 ; j < m; ++j)
	    if(g[i][j] == 'F')
	    {fx = i ; fy = j;}
    }
    q.push(mp(0,0));

    bfs();
}

int main(){
    read_input();
    return 0;
}
