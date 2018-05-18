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

int k;
string s;

int check(int val){

    int cur = 0,next = 0, pos = 0;
    int line = 1 ;

    while(pos < s.size()){
	int i;
	for(i = pos ; i < s.size() && s[i] != ' ' && s[i] != '-'; ++i );
	bool check = false;
	if(i == s.size()){
	    --i;
	    check = true;
	}
	if(cur + i - pos + 1 <= val){
	    cur += i - pos + 1; 
	    pos = i + 1;
	}
	else if(i - pos + 1 > val)
	    return 0 ;
	else{
	    cur = i - pos + 1;
	    pos = i + 1;
	    ++line;
	}

	if(check)
	    break;
    }
    return line <= k ;
}

void read_input(){
    cin >> k;
    getline(cin,s);
    getline(cin,s);

    int l = 1, r = s.size(), m ; 

    while(l <= r ){
	int m = (l+r)/2;
	if(check(m))
	    r = m - 1;
	else
	    l = m + 1;
    }

    cout << r+1 << endl;
}

int main(){
    read_input();
    return 0;
}
