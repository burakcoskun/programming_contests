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

string s;
long long res;
int mod = 1e9;

void read_input(){
    cin >> s;
    mod+=7;

    long long add = 0;
    bool check = false;

    for(int i = 0 ; i < s.size() - 1;  ++i){
	if(s[i] == 'a' && !check)
	    add = (2*add+1) % mod;
	if(s[i] == 'a' && s[i+1] == 'b'){
	    res+=add;
	    res%=mod;
	    s[i+1] = 'a';
	    s[i] = 'b';
	    check = true;
//	    add = (add - 1) % mod;
//	    add = (add / 2 ) % mod;
	}
	else
	    check = false;
    }
    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
