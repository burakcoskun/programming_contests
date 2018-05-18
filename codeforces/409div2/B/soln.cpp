#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

string x,y,z;

void read_input(){
    cin >> x >> y;
}

void calc(){
    z="";
    for(int i = 0 ; i < x.size() ; ++i)
	if(y[i] > x[i]){
	    cout << -1 << endl;
	    return;
	}

    cout << y << endl;
}

int main(){
    read_input();
    calc();
    return 0;
}
