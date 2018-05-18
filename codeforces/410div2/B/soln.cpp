#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int n;
vector<string> s;

void read_input(){
    cin >> n;
    string t;
    for(int i = 0 ; i < n ; ++i){
	cin >> t;
	s.push_back(t);
    }
}

void calc(){
    int res = 1e9 ;
    for(int i = 0; i < n; ++i){
	int move = 0 ;
	for(int j = 0 ; j < n; ++j){

	    int k ;
	    for(k = 0; k < s[0].size(); ++k){
		int l,po = 0;
		for(l = k; l < s[0].size(); ++l,++po)
		    if(s[i][po] != s[j][l])
			break;
		if(l != s[0].size())
		    continue;
		for(l = 0 ; l < k ; ++l,++po)
		    if(s[i][po] != s[j][l])
			break;

		if(l != k)
		    continue;

		move+=k;
		break;
	    }
	    if(k == s[0].size()){
		move = 1e9;
		break;
	    }
	}
	//cout << move << endl;
	res = min(res,move);
	
    }
    if(res < 1e9)
	cout << res << endl;
    else
	cout << -1 << endl;
}

int main(){
    read_input();
    calc();
    return 0;
}
