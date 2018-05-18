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

int n, a , res;

void read_input(){
    cin >> n >> a;

    int angle = (n-2)*180/n;

    double cur = angle,minA = abs(angle - a);

    res = 3;

    for(int i = 0 ; i < n - 3 ; ++i){
	cur -= (double)angle/(n-2);
	//cout << cur << " "  << minA << endl;
	if( abs(cur - a) < minA){
	    minA = abs(cur - a);
	    res = i + 4;
	}
    }

    cout << 1 << " " << 2 << " " << res << endl;
}

int main(){
    read_input();
    return 0;
}
