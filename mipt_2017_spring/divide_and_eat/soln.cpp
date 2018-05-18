#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

vector<pair<int,int> > ho,ac,bc;
int w,h,n,a,b;
map<pair<int,int>,int> res;

void read_input(){
    cin >> w >> h >> n;
    int x,y;
    for(int i = 0 ; i < n; ++i){
	cin >> x >> y;
	ho.push_back(make_pair(x,y));
    }
    cin >> a ;
    for(int i = 0 ; i < a; ++i){
	cin >> x >> y;
	ac.push_back(make_pair(x,y));
    }
    cin >> b ;
    for(int i = 0 ; i < b; ++i){
	cin >> x >> y;
	bc.push_back(make_pair(x,y));
    }

    ac.push_back(make_pair(0,0));
    ac.push_back(make_pair(h,h));
    bc.push_back(make_pair(0,0));
    bc.push_back(make_pair(w,w));

    a+=2; b+=2;

    sort(ac.begin(),ac.end());
    sort(bc.begin(),bc.end());

//    for(int i = 0; i < a ; ++i)
//	cout << ac[i].first << " " << ac[i].second << endl;
}

int check_a(int k,int pos){
    double d =ac[pos].first + (ac[pos].second - ac[pos].first)*(double)ho[k].first/w;
    return d < ho[k].second;
}

int a_search(int k){
    int l = 0, r = a-1, m ;

    while(l <= r){
	m = (l+r)/2;
	if(check_a(k,m))
	    l = m + 1;
	else
	    r = m - 1;
    }

    return r;
}

int check_b(int k,int pos){
    double d = bc[pos].second + (double)(bc[pos].first-bc[pos].second)*(double)ho[k].second/h;
//    if(k == 0 & pos == 1)
//	cout << d << " " << bc[pos].first << " " << bc[pos].second << " " << (double)ho[k].second/h*(bc[pos].first-bc[pos].second)+bc[pos].second <<  "_ " << endl;
    return d > ho[k].first;
}

int b_search(int k){
    int l = 0 , r = b-1, m;
    while(l <=r){
	m = (l+r)/2;
	if(check_b(k,m))
	    r = m - 1; 
	else
	    l = m + 1;
    }
    return l;
}

void calc(){
//    cout << check_b(0,1) << endl; 
    for(int i = 0 ; i < n; ++i){
//	cout << a_search(i) << " " << b_search(i) << endl;
	res[make_pair(a_search(i),b_search(i))]++;
    }

    int r = 0 ;
    for(map<pair<int,int>,int>::iterator it = res.begin() ; it != res.end() ;++it)
	r = max(r,it->second);
    cout << r << endl;
}

int main(){
    read_input();
    calc();
    return 0;
}
