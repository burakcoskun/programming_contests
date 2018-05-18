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

int a,b;
long long res = 1;

void read_input(){
    cin >> a >> b; 
    if(b < a)
	a = b;
    for(int i = 2 ; i <= a ; ++i)
	res *= i;
    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
