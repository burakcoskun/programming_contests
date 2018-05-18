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

int l,r;

void read_input(){
    cin >> l >> r;

    if(l == r)
	cout << l << endl;
    else
	cout << 2 << endl;
}

int main(){
    read_input();
    return 0;
}
