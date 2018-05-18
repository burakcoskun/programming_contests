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
string c;

void read_input(){
    cin >> n >> c;
    for(int i = 1; i < c.size(); ++i)
	if(c[i] == '1' && c[i-1] =='1'){
	    cout << "No" << endl;
	    return;
	}
    for(int i = 0; i < c.size(); ++i)
    	if(c[i] == '0'){
		if((i-1 < 0 || c[i-1] =='0') && (i+1 >= c.size() || c[i+1] =='0')){
		    cout << "No" << endl;
		    return;
		}
	}
    cout << "Yes" << endl;
}

int main(){
    read_input();
    return 0;
}
