#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

using namespace std;

int n,m;
string grid[1005];

struct node{
    int x,y;
    int t,d;

    bool operator < (const node & n1) const{
	return t > n1.t;
    }

};

priority_queue<node> pq;

int x[] = {1,0,-1,0};
int y[] = {0,-1,0,1};
int used[1005][1005][4];
int dx,dy;

int bfs(){
    while(!pq.empty()){
	node cn = pq.top();
	pq.pop();

//	cout << cn.x << " " << cn.y << " " << cn.t << endl; 

	used[cn.x][cn.y][cn.d] = 1;
	if(cn.x == dx && cn.y == dy)
	    return 1;

	for(int p = 0 ; p < 4; ++p){
	    int nx = cn.x + x[p];
	    int ny = cn.y + y[p];
	    if(nx >=0 && ny >= 0 && nx < n && ny <m && (grid[nx][ny] != '*' && used[nx][ny][p] == 0)){
		node n1;
		n1.x = nx ; n1.y = ny;
		n1.t = cn.t + (p!=cn.d);
		n1.d = p;
		if(n1.t <= 2)
		    pq.push(n1);
	    }
	}
    }
    return 0; 
}

void read_input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++ i){
	cin >> grid[i];
	for(int j = 0 ; j < m ; ++j){
	    if(grid[i][j] == 'S'){
		for(int k = 0; k < 4; ++k){
		    node n1;
		    n1.x = i;
		    n1.y = j;
		    n1.t = 0;
		    n1.d = k;
		    pq.push(n1);
		}
	    }
	    else if(grid[i][j] == 'T'){ dx = i ; dy = j; }
	}
    }

    if(bfs())
	cout << "YES" << endl;
    else
	cout << "NO" << endl;
}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
