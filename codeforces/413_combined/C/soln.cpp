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

#define maxn 100005

int n,c,d,minc[maxn],mind[maxn];

struct fountain{
    int b,p;
    int type;

}f[maxn];

bool comp(struct fountain &f1, struct fountain &f2){ return f1.b < f2.b; }

int check(int a){
    int r = n - 1; 

    if(a == 0 )
	return 1;

    for(int i = 0 ; i < n ; ++i){
	while(f[i].b + f[r].b >= a && r > i)
	    --r;
	if(i > r )
	    r = i ;
//	if(a >= 10 && a <=20)
//	    cout << i << " " << r << " " << a << endl;
	if(r < n-1 && f[i].b + f[r+1].b >= a){
	    if(f[i].type == 0 && (f[i].p + minc[r+1] <= c || (f[i].p <= c && mind[r+1] <= d)))
		return 1;
	    if(f[i].type == 1 && (f[i].p + mind[r+1] <= d || (f[i].p <= d && minc[r+1] <= c )))
		return 1;
	}
    }

    return 0;
}

void read_input(){
    cin >> n >> c >> d;

    for(int i = 0 ; i < n;  ++i){
	char ch;
	cin >> f[i].b >> f[i].p >> ch;
	if(ch == 'C')
	    f[i].type = 0;
	else
	    f[i].type = 1; 
    }

    sort(f,f+n,&comp);

    minc[n] = maxn*2;
    mind[n] = maxn*2;
    for(int i = n -1 ; i >=0 ; --i){
	minc[i] = minc[i+1];
	mind[i] = mind[i+1];
	if(f[i].type == 0)
	    minc[i]=min(minc[i],f[i].p);
	else
	    mind[i]=min(mind[i],f[i].p);
    }

    int l = 0 , r = f[n-1].b + f[n-2].b;
    while(l <= r){
	int m = (l+r)/2;
	if(check(m))
	    l = m + 1;
	else
	    r = m - 1;
    }

    cout << l-1 << endl;
}

int main(){
    read_input();
    return 0;
}
