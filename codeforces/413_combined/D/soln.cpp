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

int a,b,w,h,n;
int m[1 << 17];

const int inf = 1 << 17;

void read_input(){
    cin >> a >> b >> h >> w >> n;
    for(int i = 0 ; i < n; ++i)
	cin >> m [i];
    sort(m,m+n,std::greater<int>());

    int res =  min(0,1);

    if(res < inf)
	cout << res << endl;
    else
	cout << -1 << endl;
}

int main(){
    read_input();
    return 0;
}
