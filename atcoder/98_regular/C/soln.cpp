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

int n;
int cnt_e[300005];
int cnt_w[300005];
string s;
int res;

void read_input(){
    cin >> n >> s;
    res = n;

    for(int i = 0 ; i < n; ++i){
	cnt_e[i] = (s[i] == 'E');
	cnt_w[i] = (s[i] == 'W');
	if(i){
	    cnt_e[i] += cnt_e[i-1];
	    cnt_w[i] += cnt_w[i-1];
	}
    }

    for(int i = 0 ; i < n; ++i){
	int cur = 0 ;
	if(i)
	    cur = cnt_w[i-1];
	cur += (cnt_e[n-1] - cnt_e[i]);
	res = min(res,cur);
    }
    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
