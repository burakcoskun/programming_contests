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

int n,k,a[105],b[105];

void read_input(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i)
	cin >> a[i];
    for(int i = 0 ; i < k ; ++i)
	cin >> b[i];
    sort(b,b+k,greater<int>());
    int pos = 0;
    for(int i = 0 ; i < n ; ++i)
	if(a[i] == 0)
	    a[i] = b[pos++];
    for(int i = 1 ; i < n ; ++i)
	if(a[i] <= a[i-1]){
	    cout << "Yes\n";
	    return ;
	}
    cout << "No\n";
}

int main(){
    read_input();
    return 0;
}
