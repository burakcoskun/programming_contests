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

int n , a , b , res;

void read_input(){
    cin >> n >> a >> b;

    int check = 0 ; 
    int one = a; 
    int two = b;

    for(int i = 0 ; i < n  ; ++i){
	int k ;
	cin >> k ;

	if(k == 1){
	    if(one)
		--one;
	    else if(two){
		--two;
		++one;
	    }
	    else
		++res;
	}
	else{
	    if(two)
		--two;
	    else
		res+=2;
	}
    }

    cout << res << endl;
}

int main(){
    read_input();
    return 0;
}
