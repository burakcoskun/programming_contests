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

    int l = 1, r = n+1 , w = 0;

    long long res = 0; 

    while(l < r - 1 ){
	if(!w){
	    res += (l+r-1)%(n+1);
	    --r;
	}
	else{
	    res += (l+1+r)%(n+1);
	    ++l;
	}
	w = 1 - w;
    }


    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
