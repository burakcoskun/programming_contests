#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

string s1,t1,s;
int z[2000005];
int zr[2000005];
vector<int> r;
int res;

void z0(const string & s){
    int l = 1 , r = 0;
    z[0] = s.size();
    for(int i = 1; i < s.size() ; ++i){
	if ( i <= r && z[i-l] < r-i+1){
	    z[i] = z[i-l];
	    continue;
	}
	if(i > r )
	    l = r =  i;
	else 
	    l = i ;

	while(r < s.size() && s[r-l] == s[r])
	    ++r;
	z[i] = r-l;
	--r;
    }
}

void z1(const string &s){
    int l = s.size()-2 , r = s.size()-1;
    zr[s.size()-1] = 0;
    for(int i = s.size() - 2; i >= 0 ; --i){
	if ( l <= i && zr[r-i] < i-l+1){
	    zr[i] = zr[r-i];
	    continue;
	}
	if(i > l )
	    l = r =  i;
	else 
	    r = i ;

	while(r < s.size() && s[r-l] == s[r])
	    ++r;
	zr[i] = r-l;
	--r;
    }
}

void read_input(){
    cin >> t1 >> s1;
    s = t1 + "#" + s1;
    z0(s);
    s = s1 + "#" + t1;
    z1(s);

    cout << s << endl;
    for(int i = 0 ; i < s.size(); ++i)
	cout << zr[i] << " ";
    cout << endl;

    cout << r.size () << endl;
    for(int i = 0 ; i < r.size() ; ++i){
	cout << r[i] << " ";
    }
    cout << endl;
}

int main(){
    read_input();
    return 0;
}
