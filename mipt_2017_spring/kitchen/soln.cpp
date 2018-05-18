#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;
int n;
int r,c;
string p;

void read_input(){
    cin >> n >> r >> c >> p;
    int prt = 0; 
    for(int i = 0 ; i < p.size() ; ++i){

	int k = n,nc = c, nr = r;

	while(k){

	    if(!prt){
		int h = 1 << k;
		int w = h << 1; 

		if( nc > w/4 && nc <= w/4*3){
		    if( nr > h/2)
			nr -= h/2;
		}
		else
		    prt = 1 - prt;

		if(nc > w/4*3)
		    nc -= w/4*3;
		else if( nc > w/4)
		    nc -= w/4;
	    }
	    else{
		int w = 1 << k;
		int h = w << 1;

		if(nr > h/4 && nr <= h/4*3){
		    if(nc > w / 2)
			nc -= w/2;
		}
		else
		    prt = 1 - prt;

		if( nr > h/4*3)
		    nr -= h/4*3;
		else if(nr > h/4)
		    nr -= h/4;
	    }

	    --k;
	}


	if(prt == 0){
	    if(p[i] == 'U' || p[i] == 'D')
		cout << 'Y';
	    else{
		if((p[i] == 'R' && nc == 2) || (p[i]=='L' && nc == 1))
		    cout << 'Y';
		else
		    cout << 'N';
	    }
	}
	else{
	    if(p[i] == 'R' || p[i] == 'L')
		cout << 'Y';
	    else{
		if((p[i] == 'U' && nr == 1) || (p[i]=='D' && nr ==2))
		    cout << 'Y';
		else
		    cout << 'N';
	    }
	}

	if(p[i] == 'U')
	    --r;
	else if(p[i] == 'D')
	    ++r;
	else if(p[i] == 'L')
	    --c;
	else if(p[i] == 'R')
	    ++c;

	prt = 0;
    }
}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
