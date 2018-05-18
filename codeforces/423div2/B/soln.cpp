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

int n,m;
vector<string> ch;
int mleft = -1,mright = -1,top = -1,bot;

void read_input(){

    cin >> n >> m;

    for(int i = 0 ; i < n ; ++i){
	string s;
	cin >> s;
	ch.pb(s);
    }

    for(int i = 0 ; i < n ; ++i){
	for(int j = 0; j< m; ++j)
	    if(ch[i][j] == 'B'){
		if(top == -1)
		    top = i;
		if(mleft == -1)
		    mleft = j;
		mright = max(mright,j);
		bot = i;
	    }
    }

    if(top ==  -1){
	cout << 1 << endl;
	return ;
    }

    int w = mright - mleft + 1;
    int h = bot - top + 1;

    while(w > h && top){
	top--;
	++h;
    }
    while(w > h && bot < n - 1){
	++bot;
	++h;
    }
    while(h > w && mleft){
	--mleft;
	++w;
    }
    while(h > w && mright < m-1){
	++mright;
	++w;
    }
    if(w!=h)
	cout << -1 << endl;
    else{
	int res = 0 ;
	//cout << top << " " << bot << " " << mleft << " " << mright << endl;
	for(int i = top ; i <= bot ; ++i)
	    for(int j = mleft ; j <= mright ; ++j)
		res += ch[i][j]=='W';
	cout << res << endl;
    }
}

int main(){
    read_input();
    return 0;
}
