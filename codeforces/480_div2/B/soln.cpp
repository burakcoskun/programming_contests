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

int n,d;

int print_lines(int k){
    cout << "." ;
    for(int i = 0 ; i < k && i < n-2 ; ++i){
	cout << "#" ;
    }
    for(int i = min(k+1,n-1); i < n ; ++i)
	cout << ".";
    cout << endl;
    if(k > n -2)
	return k-(n-2);
    return 0;
}

void read_input(){
    cin >> n >> d;
    if(d > 2 * (n-2)){
	cout << "NO" << endl;
	return;
    }
    cout << "YES" << endl;
    for(int i = 0 ; i < n; ++i )
	cout << ".";
    cout << "\n";
    int cnt = 0;
    while(cnt < 2){
	d = print_lines(d);
	++cnt;
    }
    for(int i = 0 ; i < n; ++i )
	cout << ".";
    cout << "\n";
}

int main(){
    read_input();
    return 0;
}
