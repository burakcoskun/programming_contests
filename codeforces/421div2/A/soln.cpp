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

int c,v0,v1,a,l;

void read_input(){
    cin >> c >> v0 >> v1 >> a >> l;

    int pages_read = 0 , speed = v0;
    int day = 0 ;

    while(pages_read < c) {
	pages_read += speed;
	if(day > 0)
	    pages_read -= l;

	speed+=a;
	if(speed > v1 )
	    speed = v1;

	++day;
    }

    cout << day << endl;
}

int main(){
    read_input();
    return 0;
}
