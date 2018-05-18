#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<long long> in,s;

void read_input(){
    cin >> n;
    int a;
    for(int i = 0 ; i < n; ++i){
	cin >> a;
	in.push_back(a);
	if(i > 0){
	    s.push_back(abs(in[i-1]-in[i]));
	    if(i %2  == 0)
		s[s.size()-1] *= - 1;
	}
    }

    long long maxRes = s[0];
    long long res = s[0]; 
    for(int i = 1 ; i < s.size(); ++i){
	if(res < 0 )
	    res = 0;
	res += s[i];
	maxRes = max(res,maxRes);
    }

    for(int i = 0 ; i < s.size(); ++i) s[i] = -1 * s[i];

    res = s[0];
    for(int i = 1 ; i < s.size(); ++i){
	if(res < 0 )
	    res = 0;
	res += s[i];
	maxRes = max(res,maxRes);
    }
    cout << maxRes;
}

int main(){
    read_input();
    return 0;
}
