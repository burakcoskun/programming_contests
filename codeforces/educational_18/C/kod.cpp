#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string n;

void read_input(){
    cin >> s;
    int m = 0;
    for(i=0;i<s.size();++i){
	m+=(s[i]-'0');
	m%=3;
    }
}

int main(){
    read_input();
    return 0;
}
