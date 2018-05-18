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

int n,S;
long long a[100005],b[100005];
long long res = 0;

bool check(long long k){
    for(int i = 0 ; i < n;++i)
	b[i] = a[i] + (i+1)*k;
    sort(b,b+n);
    long long sum = 0; 
    for(int i = 0 ; i < k;++i)
	sum+= b[i];
    if(sum <= S){
	res = sum;
	return true;
    }
    return false;
}

void read_input(){
    cin >> n >> S;
    for(int i = 0 ; i < n ; ++i)
	cin >> a[i];

    int l = 0 , r = n; 
    while(l <= r ){
	int m = (l +r)/2;
	if(check(m))
	    l = m + 1; 
	else
	    r = m - 1;
    }
    cout << l-1 << " " << res << endl;
}

int main(){
    read_input();
    return 0;
}
