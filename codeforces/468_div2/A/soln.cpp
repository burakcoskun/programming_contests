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
int res;

void read_input(){
    cin >> a >> b;

    int step1 = (abs(a-b) + 1)/2;
    int step2 = abs(a-b)/2;

    res = step1*(step1+1)/2 + step2*(step2+1)/2;
    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
