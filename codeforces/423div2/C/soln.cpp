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
char res[2000005];

void read_input(){
    cin >> n; 

    int len = 0 ;

    for(int i = 0 ; i <  n; ++i){
	string s;
	int k;
	int pos = 0 ; 
	cin >> s >> k;
	for(int j = 0 ; j < k; ++j){
	    int x;
	    cin >> x;

	    int p = 0;

	    if(pos <= x){
		p = 0;
		pos = x;
	    }

	    else
		p = pos - x;

	    for(; p < s.size() ;++p)
		res[pos++] = s[p];
	    len = max(len,pos);
	}
    }

    for(int i = 1; i < len;++i)
	if(!res[i])
	    res[i] = 'a';
    cout << (char*)(res+1) << endl;
}

int main(){
    read_input();
    return 0;
}
