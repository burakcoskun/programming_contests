#include<cstdio>
#include<cstdlib>
#include<string>
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

int n,k;
pair<int , int> days[100005];
pair<int , int> p[100005];
long long res;

void read_input(){
    cin >> n >> k ;
    for(int i = 0 ; i < n; ++i){
	cin >> days[i].fs >> days[i].sc;
	p[i].fs = min(days[i].fs*2,days[i].sc) - min(days[i].fs,days[i].sc);
	p[i].sc = i ;
    }

    sort(p,p+n, std::greater<pair<int,int> >());
    for(int i = 0 ; i < k ; ++i)
	days[p[i].sc].fs *= 2;

    for(int i = 0 ; i < n;  ++i)
	res += min(days[i].fs,days[i].sc);

    cout << res << endl;

}

int main(){
    read_input();
    return 0;
}
