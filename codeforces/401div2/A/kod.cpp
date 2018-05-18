#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,x;

void read_input(){
    cin >> n >> x;
    n%=6;
    while(n){
	if(n%2 == 0){
	    if(x == 1)
		x = 2;
	    else if(x == 2)
		x = 1;
	}
	else{
	    if(x == 0)
		x = 1;
	    else if(x == 1)
		x = 0;
	}
	n--;
    }
    cout << x;
}

int main(){
    read_input();
    return 0;
}
