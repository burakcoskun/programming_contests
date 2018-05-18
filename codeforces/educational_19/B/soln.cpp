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

int n;
int a[200005],l[200005],r[200005];

const int inf = 1e8;

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n; ++i)
	cin >> a[i];

    int pos = -1*inf;
    for(int i = 0 ; i < n; ++i){
	if(a[i] == 0)
	    pos = i;
	l[i] = i - pos;
    }

    pos = inf;
    for(int i = n - 1; i >= 0 ; --i){
	if(a[i] == 0)
	    pos = i;
	r[i] = pos - i;
    }

    for(int i = 0 ; i <  n; ++i)
	cout << min(l[i],r[i]) << " ";
    cout << endl;
}

int main(){
    read_input();
    return 0;
}
