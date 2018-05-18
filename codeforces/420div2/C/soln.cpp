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

int n,res = 0;

void read_input(){
    cin >> n; 

    n <<= 1;
    string s;
    int cnt = 0 ;

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i = 0 ; i  < n ; ++i){
	cin >> s;;

	if(s[0] == 'a'){
	    int num;
	    cin >> num;
	    if(pq.empty() || num < pq.top())
		++cnt;
	    else
		cnt = 0 ;
	    pq.push(num);
	}

	else{
	    pq.pop();
	    --cnt;
	    if(cnt < 0 ){
		++res;
		cnt = pq.size();
	    }
	}
    }

    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
