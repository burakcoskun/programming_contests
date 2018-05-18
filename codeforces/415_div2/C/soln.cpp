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

const int mod=1e9+7;
int n;
int x[300005],sum[300005];

int mul(int a,int b){
    long long mult = (long long)a * b;
    return mult % mod;
}
int add(int a,int b){
    long long res = (long long)a+b;
    return res % mod;
}
int subt(int a,int b){
    int res = a - b;
    if(res < 0)
	res += mod ;

    return res;
}

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n; ++i)
	cin >> x[i];

    if(n < 2 ){
	cout << 0 << endl;
	return ;
    }

    sort(x,x+n);

    sum[0] = x[0];
    for(int i = 1 ; i < n; ++i)
	sum[i] = add(sum[i-1],x[i]);

    long long c = x[n-1] - x[n-2], pow = 1;
    long long res = c;

    for(int i = n - 3 ; i >= 0 ; --i){
	c = x[i+1] - x[i];
	res = add(res,mul(res,c)); 
	cout << res << endl;
	res = add(res,sum[n-1]-sum[i]);
//	cout << res << endl;
	res = subt(res,mul(n-1-i,x[i]));
//	cout << res << endl;
//	pow = mul(pow,2);

//	res += pow * c;
    }

    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
