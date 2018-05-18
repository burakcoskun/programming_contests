#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> c1,c2;
int used[1005];

void read_input(){
    cin >> n;
    char ch;
    for(int i = 0 ; i < n; ++i){
	cin >> ch;
	c1.push_back(ch-'0');
    }
    for(int i = 0 ; i < n; ++i){
	cin >> ch;
	c2.push_back(ch-'0');
    }
    sort(c1.begin(),c1.end(),std::greater<int>());
    sort(c2.begin(),c2.end(),std::greater<int>());

    int r1 = 0 , r2 = 0;
    int lpos = 0 , rpos = n-1;
    for(int i = 0 ; i < n; ++i){
	if(c2[lpos] > c1[i]){
	    r1++;
	    lpos++;
	}
    }
    lpos = 0 ;
    for(int i = 0 ; i < n; ++i){
	if(c2[lpos] >= c1[i]){
	    lpos ++ ;
	}
	else r2++;
    }
    cout << r2 << "\n" << r1 << "\n";
}

int main(){
    read_input();
    return 0;
}
