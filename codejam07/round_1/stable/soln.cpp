#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int t,n;
int cnt[6];
vector<int> res;

void read_input(){
    cin >> t;
    for(int i = 0; i < t ; ++i){
	cin >> n;

	for(int j = 0 ; j < 6; ++j)
	    cin >> cnt[j];

	cout << "Case #" << (i+1)  << ": ";
	int j;
	res.clear();
	for(j = 0 ; j < n; ++j){
	    int k;
	    for(k = 0 ; k < 6; ++k)
		if(cnt[k]){
		    if(res.size() == 0){
			res.push_back(k);
			break;
		    }
		    int p ;
		    for(p = 0 ; p < res.size(); ++p)
			if(k!=res[p] &&(j < n-1 ||  k!=res[(p+1)%res.size()])){
			    res.insert(res.begin()+p+1,k);
			    break;
			}
		    if(p < res.size())
			break;
		}
	    if(k == 6){
		cout << "IMPOSSIBLE" << endl;
		break;
	    }

	    --cnt[k];
	}

	if(j == n){
	    for(int k = 0; k< res.size(); ++k){
		if(res[k] == 0)
		    cout << 'R';
		else if(res[k] == 2)
		    cout << 'Y';
		else if(res[k] == 4)
		    cout << 'B';
	    }
	    cout << endl;
	}
    }
}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
