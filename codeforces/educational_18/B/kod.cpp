#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n,k;
vector<int> ch;

void read_input(){
    scanf(" %d %d",&n,&k);
    int a , l = 0;
    for(int i = 0 ; i<n;++i)
	ch.push_back(i);
    for(int i = 0 ; i < k; ++i){
	scanf(" %d",&a);

	int p = (l+a)%n;
	printf("%d ",ch[p]+1);
	ch.erase(ch.begin()+p);
	l = p ;
	n--;
    }
}

int main(){
    read_input();
    return 0;
}
