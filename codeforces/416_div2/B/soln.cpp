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

int n,m,p[10005],p1[10005];

void read_input(){
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i)
	cin >> p[i];

    int l,r,x;
    for(int i = 0 ; i < m ; ++i){

	for(int j = 0; j < n; ++j)
	    p1[j] = p[j];

	cin >> l >> r >> x;
	--l;  --x;
	
	sort(p1+l,p1+r);
/*	for(int j = 0; j < n;++j)
	    cout << p1[j] << " " ;
	cout << endl;*/
	if(p1[x] == p[x])
	    cout << "Yes" << endl;
	else
	    cout << "No" << endl;
    }
}

int main(){
    read_input();
    return 0;
}
