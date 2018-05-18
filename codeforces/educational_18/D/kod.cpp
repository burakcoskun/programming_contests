#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long int n;
int q;
long long int u;

void read_input(){
    cin >> n >> q;;
    string s;
    for(int i = 0 ; i < q; ++i){
	cin >> u >> s;
	
	long long c = (n+1)/2;
	long long jump = (n+1);
	while(c != u){
	    if( u > c)
		c += (jump)/4;
	    else
		c -= (jump)/4;
	    jump/=2;
	}

	jump/=2;

	for(int j = 0 ; j < s.size() ; ++j){
	    if(s[j] == 'U' && u != (n+1)/2){
		if(((u - jump)/(jump*2)) % 2 == 0)
		    u += jump;
		else 
		    u -= jump;
		jump*=2;
	    }
	    else if(s[j] =='R' && u % 2 == 0){
		u+=jump/2;
		jump/=2;
	    }
	    else if(s[j] =='L' && u % 2 == 0 ){
		u-=jump/2;
		jump/=2;
	    }
	    //printf("%d %d\n",u,jump);
	}
	cout << u << "\n";
    }
}

int main(){
    read_input();
    return 0;
}
