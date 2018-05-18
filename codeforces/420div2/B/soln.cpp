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

long long m,b;
long long w,h;
long long res;

void read_input(){
    cin >> m >> b;
    long long cur = 0 ;
   // cout << h << " " << w << endl;

    for(long long i = 0 ; i < b ; ++i){

	long long x = (b - i)*m;

	cur = (x)*(x+1)/2*(i+1)+i*(i+1)/2*(x+1);

//	cout << x << " " << cur << endl;
	res = max(res,cur);
    }

    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
