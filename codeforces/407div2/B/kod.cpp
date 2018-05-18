#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long long b1,q,l,m;
vector<long long> bad;

bool b_search(long long k){
    long long l = 0, r = m-1;

    while(l <= r){
	int middle = (l+r)/2;
	if(bad[middle] == k)
	    return true;
	else if(bad[middle] > k)
	    r = middle - 1;
	else
	    l = middle + 1;
    }
    return false;
}

void calc(){
    long long b = b1;
    long long res = 0 ;
    while(abs(b) <= l){
	if(b_search(b) == false)
	    res ++ ;
	b *= q;
    }
    cout << res;
}

void read_input(){
    cin >> b1 >> q >> l >> m;
    int a;
    for(int i = 0 ; i < m ; ++i){
	cin >> a;
	bad.push_back(a);
    }
    sort(bad.begin(),bad.end());

    if(b1 == 0 ){
	if(b_search(0)){
	    printf("0\n");
	}
	else
	    printf("inf\n");
    }
    else if(q == 0){
	int res = 0 ;
	if(b_search(0) == false){
	    printf("inf\n");
	    return;
	}
	else if(abs(b1) <= l && b_search(b1) == false)
	    res++;
	printf("%d\n",res);
    }
    else if(q == 1){
	if(b_search(b1) || abs(b1) > l)
	    printf("0\n");
	else
	    printf("inf\n");
    }
    else if(q == -1){
	int res = 0 ;
	if(abs(b1) > l || (b_search(b1) && b_search((b1*-1))))
	    printf("0\n");
	else printf("inf\n");
    }
    else{
	calc();
    }
}

int main(){
    read_input();
    return 0;
}
