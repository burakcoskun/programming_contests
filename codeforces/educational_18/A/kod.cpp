#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> city;

void read_input(){
    scanf(" %d",&n);
    int r1 = 2e9+100, r2 = 0;
    int a;
    for(int i = 0 ; i < n; ++i){
	scanf(" %d",&a);
	city.push_back(a);
    }
    sort(city.begin(),city.end());
    for(int i = 0 ; i<city.size() - 1; ++i){
	if(abs(city[i+1] - city[i]) < r1){
	    r1 = abs(city[i+1] - city[i]);
	    r2 = 1;
	}
	else if(abs(city[i+1]-city[i]) == r1)
	    r2++;
    }
    printf("%d %d\n",r1,r2);
}

int main(){
    read_input();
    return 0;
}
