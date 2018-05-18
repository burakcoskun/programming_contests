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

int T,c,j;
pair<int,int> ac[105],aj[105];

void read_input(){
    cin >> T;
    for(int t = 0 ; t < T ; ++t){
	cin >> c >> j;
	for(int i = 0 ; i < c ; ++i)
	    cin >> ac[i].first >> ac[i].second;
	for(int i = 0 ; i < j ; ++i)
	    cin >> aj[i].first >> aj[i].second;

	sort(ac, ac+c);
	sort(aj, aj+j);

	int res ;
	if(c < 2 && j < 2) res = 2;
	else if(c == 2){
	    if(ac[1].second - ac[0].first <= 720 || 1440-ac[1].first+ac[0].second <= 720)
		res = 2;
	    else
		res = 4;
	}
	else if(j == 2){
	    if(aj[1].second - aj[0].first <= 720 || 1440-aj[1].first+aj[0].second <= 720)
		res = 2;
	    else res =4;
	}

	cout << "Case #" << t+1 << ": " << res << endl;
    }
}

int main(){
    read_input();
    return 0;
}
