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

int n,t,k,d;

void read_input(){
    cin >> n >> t >> k >> d;
    int div = n/k;
    if(n%k)
	div++;
    if(div * t > d + t )
	cout << "YES" << endl;
    else
	cout << "NO" << endl;
}

int main(){
    read_input();
    return 0;
}
