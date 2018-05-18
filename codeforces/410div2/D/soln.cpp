#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int a[1 << 20],b[1 << 20],c[1 << 20];
int n;

bool comp(int x,int y){ return a[x] > a[y]; } 

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
	cin >> a[i];
    for(int i = 0 ; i < n ; ++i)
	cin >> b[i];

    for(int i = 0 ; i < n ; ++i)
	c[i] = i ;

    sort(c,c+n,&comp);

    cout << n/2+1 << endl;
    cout << c[0] + 1 << " ";
    for(int k = 1 ; 2*k < n; ++k){
	if(b[c[2*k]] > b[c[2*k-1]])
	    cout << c[2*k]+1 << " ";
	else
	    cout << c[2*k-1]+1 << " ";
    }
    if(n % 2 == 0)
	cout << c[n-1]+1 ;
    cout << endl;
}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
