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

priority_queue<pair<int,int>> ex;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> in;
int n;
string s;

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n; ++i){
	int a;
	cin >> a;
	in.push(mp(a,i+1));
    }

    cin >> s;

    for(int i = 0 ; i < s.size(); ++i){
	if(s[i] == '0'){
	    pair<int,int> top = in.top();
	    in.pop();
	    ex.push(top);
	    cout << top.sc << " " ;
	}
	else{
	    cout << ex.top().second << " ";
	    ex.pop();
	}
    }
    cout << endl;
}

int main(){
    read_input();
    return 0;
}
