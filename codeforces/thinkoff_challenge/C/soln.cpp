#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

int n;

pair<double,double> c0,c1;
pair<int,int> m[1 << 20], v[1 << 20];
pair<double,double> t[1 << 20];

void calc(){
    for(int i = 0 ; i < n; ++i){
	pair<double,double> t1,t2;

	if(v[i].first >= 0){
	    if(m[i].first >= c0.first && m[i].first <= c1.first)
		t1.first = 0 ;
	    else
		t1.first = (double)(c0.first - m[i].first)/v[i].first;

	    if(v[i].first > 0)
		t1.second = (double)(c1.first - m[i].first)/v[i].first ;
	    else
		t1.second = 1e15;
	}
	else{
	    if(m[i].first >= c0.first && m[i].first <= c1.first)
		t1.first = 0;
	    else
		t1.first=(double)(m[i].first - c1.first)/abs(v[i].first);

	    t1.second = (double)(m[i].first - c0.first)/abs(v[i].first);
	}

	if(v[i].second >= 0 ){
	    if(m[i].second >= c0.second && m[i].second <= c1.second)
		t2.first = 0;
	    else
		t2.first = (double)(c0.second - m[i].second)/v[i].second;

	    if(v[i].second >0)
		t2.second = (double)(c1.second -m[i].second)/v[i].second;
	    else
		t2.second = 1e15;
	}
	else{
	    if(m[i].second >= c0.second && m[i].second <= c1.second)
		t2.first = 0;
	    else
		t2.first = (double)(m[i].second - c1.second)/abs(v[i].second);

	    t2.second = (double)(m[i].second - c0.second)/abs(v[i].second);
	}

	t[i].first = max(t1.first,t2.first);
	t[i].second = min(t1.second,t2.second);

	//cout << t[i].first << " " << t[i].second << endl;
//	cout << c1.first << " " << m[i].first << "__"<<endl;
//	cout << (c1.first - m[i].first)<< t1.second << " " << t2.second << endl;

    }
}

void read_input(){
    cout.precision(17);

    pair<double,double> t1 = c0, t2 = c1;

    cin >> n;
    cin >> t1.first >> t1.second >> t2.first >> t2.second;

    c0.first = min(t1.first,t2.first);
    c0.second = min(t1.second,t2.second);
    c1.first = max(t1.first,t2.first);
    c1.second = max(t1.second,t2.second);

    c0.first  += 0.000000000001;
    c0.second += 0.000000000001;
    c1.first  -= 0.000000000001;
    c1.second -= 0.000000000001;

    for(int i = 0 ; i <  n; ++i){
	cin >> m[i].first >> m[i].second >> v[i].first >> v[i].second ;
	if((m[i].first < c0.first && v[i].first <= 0) 
		|| (m[i].first > c1.first && v[i].first >= 0)
		|| (m[i].second < c0.second && v[i].second <= 0)
		|| (m[i].second > c1.second && v[i].second >= 0)){
	    cout << -1 << endl;
	    return ;
	}
    }

    calc();

    pair<double,double> res = t[0];
    for(int i = 1; i < n; ++i){
	res.first = max(res.first,t[i].first);
	res.second = min(res.second,t[i].second);
    }
    if(res.first > res.second)
	cout << -1 << endl;
    else
	cout << res.first << endl;
}


int main(){
    read_input();
    return 0;
}
