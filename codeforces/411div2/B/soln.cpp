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

int n;

void read_input(){
    cin >> n;
    string s;
    for(int i = 0 ; i < 2 && i < n ;++i)
	s+='a';
    for(int i = 2; i < n; ++i){
	if(s[i-2] == 'a')
	    s+='b';
	else
	    s+='a';
    }

    cout << s << endl;
}

int main(){
    read_input();
    return 0;
}
