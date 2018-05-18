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

int a,b,c;
int n;
//int x[100005];
int res;

void read_input(){
    cin >> a >> b >> c >> n;
    int x;
    for(int i = 0 ; i < n; ++i){
	cin >> x;
	if(x > b &&  x < c)
	    res++;
    }

    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
