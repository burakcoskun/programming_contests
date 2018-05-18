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

int p,d;

void read_input(){
    string s;
    cin >> s;
    for (int i = 0 ; i < s.size() ; ++i){
	if(s[i] =='o')
	    ++p;
	else
	    ++d;
    }

    if(!p || d % p == 0)
	cout << "YES" << endl;
    else
	cout << "NO" << endl;
}

int main(){
    read_input();
    return 0;
}
