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

int n,m,res;
vector<int> p;
string s , t;

void read_input(){
    cin >> n >> m >> s >> t;

    res = s.size()+1;

    for(int i = 0 ; i < t.size() - s.size() +1 ;++i){

	int cnt = 0 ;
	vector<int> pos;
	for(int j = 0 ; j < s.size(); ++j)
	    if(s[j] != '?' && t[i+j] != s[j]){
		++cnt;
		pos.pb(j+1);
		//cout << j +1 << endl;
	    }

	if ( res > cnt ){
	    res = cnt;
	    p = pos;
	}
    }


    cout << res << endl;
    if(p.size()){
	    for(int i = 0 ; i < p.size(); ++i)
		cout << p[i] << " " ;
	    cout << endl;
    }
}

int main(){
    read_input();
    return 0;
}
