#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,k;
long long res;

void read_input(){
    cin >> n >> k;

    int w;
    for(int i = 0 ; i < n; ++i){
	cin >> w;
	
	if(w % k == 0)
	    res += w/k;
	else
	    res += w/k+1;
    }
    res++;
    res/=2;
    cout << res;
}

int main(){
    read_input();
    return 0;
}
