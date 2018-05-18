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

int l[4][4];

int mod(int k){
    if(k == 4)
	return 0;
    if(k == -1)
	return 3;
    return k;
}

int read_input(){
    for(int i = 0 ; i < 4; ++i)
	for(int j = 0; j < 4 ; ++j)
	    cin >> l[i][j];

    for(int i = 0 ; i < 4; ++i){
	if(l[i][0] && (l[i][3] || l[mod(i-1)][3]))
	    return 1;
	if(l[i][1] && l[i][3])
	    return 1;
	if(l[i][2] && (l[i][3] || l[mod(i+1)][3]))
	    return 1;
    }
    return 0;
}

int main(){
    if(read_input())
	cout << "YES\n";
    else
	cout << "NO\n";
    return 0;
}
