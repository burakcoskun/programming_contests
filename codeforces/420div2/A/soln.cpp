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

vector<vector<int>> mat(55,vector<int>(55,0));
int n;

void read_input(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
	for(int j = 0 ; j < n ; ++j)
	    cin >> mat[i][j];
    for(int i = 0 ; i < n; ++i)
	for(int j = 0; j < n; ++j)
	    if(mat[i][j] != 1){
		bool res = false;
		for(int k = 0 ; k < n; ++k)
		    for(int l = 0 ; l < n ;++l)
		   	if(mat[i][k]+mat[l][j] == mat[i][j])
				res = true;
		if(!res){
		    cout << "No" << endl;
		    return ;
		}
	    }

    cout << "Yes" << endl;
}

int main(){
    read_input();
    return 0;
}
