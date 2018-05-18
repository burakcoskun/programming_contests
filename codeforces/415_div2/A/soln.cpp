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

int n , k , sum;

void read_input(){
    int a; 
    cin >> n >> k; 
    for(int i = 0 ; i < n; ++i ){
	cin >> a ;
	sum += a;
    }

    for(int res = 0 ; ; ++res){
	if((double)(sum + res * k ) / (n+res) >= (double)k - 0.5){
	    cout << res << endl;
	    break;
	}
    }
}

int main(){
    read_input();
    return 0;
}
