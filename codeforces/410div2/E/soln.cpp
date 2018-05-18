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

int n;
int e[500005];
int r[500005];
int cnt;

void ts(int pos){
    if(r[pos])
	return ;
    if(e[pos] >= 0 )
	ts(e[pos]);
//    cout << pos << endl;
    r[pos] = cnt--;
}

void read_input(){
    cin >> n;
    cnt = n;

    int a;
    for(int i = 0 ; i < n;  ++i){
	cin >> a;
	e[i] = a - 1 ;
    }

    for(int i = 0 ; i < n; ++i)
	if(!r[i])
	    ts(i);

    for(int i = 0 ; i < n; ++i)
	cout << r[i] << " " ;
    cout << endl;
}

int main(){
    read_input();
    return 0;
}
