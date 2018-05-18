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

long long n,k;

void read_input(){
    cin >> n >> k ;

    if(k > 1e8 || k*(k+1)/2 > n){
	cout << -1 << endl;
	return ;
    }

    long long res = 1;
    for(long long i = 1; i * i <= n; ++i){
	if(n%i == 0){
	    if(n/i >= k*(k+1)/2)
		res = max(res,i);

	    if(i >= k*(k+1)/2)
		res = max(res,n/i);
	}
    }

    long long sum = 0; 
    for(int i = 0 ; i < k -1; ++i){
	cout << (i+1)*res << " ";
	sum += (i+1)*res;
    }
    cout << n - sum << endl;
}

int main(){
    read_input();
    return 0;
}
