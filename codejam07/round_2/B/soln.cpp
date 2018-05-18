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

int T,n,c,m;
pair<int,int> p0[1005],p1[1005];

void read_input(){
    cin >> T ;

    for(int t = 0 ; t < T ; ++t ){
	cin >> n >> c >> m ;


	memset(p0, 0 , sizeof p0);
	memset(p1, 0 , sizeof p1);

	int p,b;
	for(int i = 0 ; i < m; ++i){
	    cin >> p >> b;
	    if(b == 1 )
		p0[p-1].fs++;
	    else
		p1[p-1].fs++;
	}

	for(int i = 0 ; i < n; ++i)
	    p0[i].sc = p1[i].sc = i;

	int res = 0 , pr = 0 ;

	sort(p0,p0+n,std::greater<pair<int,int> >());
	sort(p1,p1+n,std::greater<pair<int,int> >());
	
	for(int i = 0 ; i <n; ++i){
	    if(p0[i].fs){
		for(int j = 0 ; j < n; ++j)
		    if(p0[i].sc != p1[j].sc){
			{
			    res += min(p0[i].fs,p1[j].fs);
			    int a = p0[i].fs, b = p1[j].fs;
			    p0[i].fs -= min(a,b);
			    p1[j].fs -= min(a,b);
			}
		    }
		for(int j = 0 ; j< n; ++j)
		    if(p0[i].sc > 0 && p0[i].sc == p1[j].sc){
			int a = p0[i].fs, b = p1[j].fs;
			res += min(a,b);
			pr  += min(a,b);
			p0[i].fs -= min(a,b);
			p1[j].fs -= min(a,b);
			break;
		    }
		res+= p0[i].fs;
		p0[i].fs = 0 ;
		sort(p0,p0+n,std::greater<pair<int,int> >());
		sort(p1,p1+n,std::greater<pair<int,int> >());
		i = -1;
	    }
	}
	for(int i = 0 ; i < n; ++i)
	    res+=p1[i].fs;

	cout << "Case #" << t+1 << ": " << res << " " << pr << endl;
    }
}

int main(){
    read_input();
    return 0;
}
