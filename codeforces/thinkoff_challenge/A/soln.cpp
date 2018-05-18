#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int n,k;
int a[1 << 20];
long long res;

void read_input(){
    cin >> n >> k;
    for(int i = 0 ; i < n; ++i)
	cin >> a[i];
    sort(a,a+n);

    for(int i = 1; i < n; ++i){
	if((a[i] - a[0]) % k != 0 ){
	    cout << -1 << endl;
	    return;
	}
	else
	    res += (a[i]-a[0]) / k ;
    }
    cout << res << endl;
}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
