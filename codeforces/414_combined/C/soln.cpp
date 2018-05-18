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
#include<cstring>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

char s[300005],t[300005],r[300005];
int n;

void read_input(){
    scanf(" %s %s",s,t);

    n = strlen(s);

    sort(s,s+n);
    sort(t,t+n);

    int s1 = 0 , s2 = n-1;
    int t1 = 0 , t2 = n-1;

    int r1 = 0 , r2 = n-1;

    for(int i = 0 ; i < n ; ++i){
	if(i % 2 == 0){
	    if(s[s1] < t[t2])
		r[r1++] = s[s1++];
	    else
		r[r2--] = s[s2--];
	    //cout << s[p1++];
	}
	else{
	    if(t[t2] > s[s1])
		r[r1++] = t[t2--];
	    else
		r[r2--] = t[t1++];
	}
    }
    cout << r <<  endl;
}

int main(){
    read_input();
    return 0;
}
