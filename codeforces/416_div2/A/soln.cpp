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

int a, b;

void read_input(){
    cin >> a >> b;

    for(int i = 1 ; ; ++i){
	if(i % 2){
	    if(a < i){
		cout << "Vladik" << endl;
		break;
	    }
	    a -= i;
	}
	else{
	    if(b < i){
		cout << "Valera" << endl;
		break;
	    }
	    b -= i;
	}
    }
}

int main(){
    read_input();
    return 0;
}
