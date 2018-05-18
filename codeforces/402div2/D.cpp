#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

string t,p;
int a[200005];
bool mark[200005];

bool check(int k){
    for(int i=0;i<t.size();++i)
	mark[i] = 0; 
    for(int i = 0 ; i<k;++i)
	mark[a[i]-1] = true;
    int pos = 0 ;
    for(int i=0;i<t.size();++i){
	if(mark[i])
	    continue;
	if(t[i] == p[pos])
	    pos ++;
	if(pos == p.size())
	    break;
    }
    return pos == p.size();
}

int bin_search(){
    int l=0 , r=t.size()-1;

    while (l <= r ){
	int m  = (l+r)/2;
	if(check(m))
	    l = m+1;
	else
	    r = m-1;
    }
    return l-1;
}

int main(){
    cin >> t >> p;
    for(int i = 0 ; i < t.size() ; ++i)
	scanf(" %d",&a[i]);
    printf("%d\n",bin_search());
    return 0;
}

