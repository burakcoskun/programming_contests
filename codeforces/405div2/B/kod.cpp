#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,start[150005],last[150005];
vector<pair<int,int> > edges;

void read_input(){
    int a,b;
    scanf(" %d %d",&n,&m);
    if(m == 0)
	return;
    for(int i=0;i<m;++i){
	scanf(" %d %d",&a,&b);
	edges.push_back(make_pair(a,b));
	edges.push_back(make_pair(b,a));
    }
    sort(edges.begin(),edges.end());
    for(int i = 1; i <= n; ++i)start[i] =last[i] =-1;
    start[edges[0].first] = 0;
    for(int i=1;i<edges.size();++i)
	if(edges[i].first != edges[i-1].first){
	    start[edges[i].first] = i;
	    last[edges[i-1].first] = i-1;
	}
    last[edges[edges.size()-1].first] = edges.size()-1;
}

bool search(int k,int l,int r){
    if(l < 0 || r < 0)
	return false;
   // printf("%d %d %d\n",k,l,r);
    while(l <= r){
	int m = (l+r)/2;
	if(k == edges[m].second)
	    return true;
	else if(k < edges[m].second)
	    r = m -1;
	else
	    l = m+1;
    }
    //printf("%d %d %d\n",k,l,r);
    return false;
}

bool calc(){
    for(int i = 0; i<edges.size();++i)
	for(int j = start[edges[i].second]; j < edges.size() && edges[j].first == edges[i].second ; ++j){
	    if(edges[j].second <= edges[i].first)
		continue;
	    bool check = search(edges[i].first,start[edges[j].second],last[edges[j].second]);
/*	    for(int k = start[edges[j].second]; k < edges.size() && edges[k].first == edges[j].second ; ++k){
		if(edges[k].second == edges[j].first)
		    continue;
		if(edges[k].second == edges[i].first){
		    check = true ;
		    break;
		}
	    }*/
	    if(check == false)
		return false;
	}
    return true;
}

int main(){
    read_input();
    if(m == 0 || calc())
	cout << "YES\n";
    else
	cout << "NO\n";
    return 0;
}
