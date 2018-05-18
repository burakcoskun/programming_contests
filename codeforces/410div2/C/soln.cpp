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
vector<int> a;

int gcd(int a,int b){
    if(a == 0)
	return b;
    if(b == 0)
	return a;
    return gcd(b,a%b);
}

void read_input(){
    cin >> n;
    int t;
    for(int i = 0 ; i < n; ++i){
	cin >> t;
	a.push_back(t);
    }
}

void calc(){
    int g = a[0];
    int res = 0 ;
    int worstRes = 0;
    cout << "YES" << endl;
    for(int i = 0 ; i < n; ++i)
	if(a[i] % 2){
	    if(i < n && (a[i]%2) && (a[i+1]%2))
		worstRes++;
	    else
		worstRes +=2;
	    i++;
	}
    for(int i = 1; i < n; ++i){
	int t = gcd(g,a[i]);
	if(t > 1){
	    g = t;
	    continue;
	}
	t = gcd(abs(g-a[i]),g+a[i]);
	if( t > 1){
	    g = abs(t);
	    res++;
	    continue;
	}
	else{
	    cout << worstRes << endl; 
	    return;
	}
    }

    cout << res << endl;
}

int main(){
    read_input();
    calc();
    return 0;
}
