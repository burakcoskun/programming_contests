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

int n;
int a[100005];

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
	cin >> a[i];
}

int main(){
    read_input();
    return 0;
}
