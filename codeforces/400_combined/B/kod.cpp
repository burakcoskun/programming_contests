#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>

using namespace std;

int n;
long long k;
vector<long long> p;
vector<long long> w;
map<long long,int> sum;

void read_input(){
    cin >> n >> k;
    int a;
    p.push_back(0);
    for(int i = 0 ; i < n; ++i){
	cin >> a;
	p.push_back(a+p[i]);
    }
    w.push_back(1);
    if(k == -1)
	w.push_back(k);
    else if( k != 1){
	long long t = k;
	while(abs(t) <= 1e15){
	    w.push_back(t);
	    t *= k;
	}
    }
}

void calc(){
    long long res = 0 ;
    for(int i = 0 ; i < n; ++i){
	sum[p[i]]++;
	for(int j = 0 ; j < w.size() ; ++j){
	    map<long long,int>::iterator it = sum.find(p[i+1]-w[j]);
	    if(it != sum.end())
	   	 res += it->second;
	}
    }
    cout << res; 
}

int main(){
    read_input();
    calc();
    return 0;
}
