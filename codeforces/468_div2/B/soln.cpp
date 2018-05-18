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

int n,a,b;

int solve(int a,int b,int n){
    if(n == 2)
	return 1;

    if(a > n/2 && b > n/2)
	return solve(a-n/2, b-n/2, n/2);
    if(a <= n/2 && b <= n/2)
	return solve(a,b,n/2);
    int res = 0; 
    while(n > 1){
	++res;
	n/=2;
    }
    return res;
}

void read_input(){
    cin >> n >> a >> b;

    if(a > b)
	swap(a,b);

    int res = solve(a,b,n);
    int k = 1 , cnt = 0;
    while(k < n ){ k *=2; ++cnt;}
    if(res == cnt)
	cout << "Final!" << endl;
    else
	cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
