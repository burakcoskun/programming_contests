#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n , q , m;
string s;
char fav;

void read_input(){
    cin >> n >> s >> q;
    for(int i = 0 ; i < q ; ++i){
	cin >> m >> fav;

	int cnt1 = 0 , cnt2 = 0;
	int left = 0 , res = 0 ;

	for(int j = 0 ; j < n ; ++j){
	    if(s[j] == fav)
		++cnt1;
	    else
		++cnt2;
	    while(cnt2 > m && left <=j){
		if(s[left] == fav)
		    --cnt1;
		else
		    --cnt2;

		++left;
	    }

	    res = max(res,j - left + 1);
	}
	cout << res << endl;
    }
}

int main(){
    read_input();
    return 0;
}
