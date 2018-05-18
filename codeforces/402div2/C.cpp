#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

int n,k,res;
vector<pair<int,int> > p;

bool comparator(pair<int,int> &lhs,pair<int,int> &rhs){
    return lhs.first - lhs.second < rhs.first - rhs.second;
}

void read(){
    int a;
    scanf(" %d %d",&n,&k);
    for(int i = 0 ; i < n; i++){
	scanf( " %d",&a);
	p.push_back(make_pair(a,0));
    }
    for(int i = 0 ; i < n; ++i)
	scanf(" %d",&p[i].second);
    
    sort(p.begin(),p.end(),comparator);

    for(int i = 0 ; i < k; ++i)
	res +=p[i].first;
    for(int i = k ; i < n; ++i){
	if(p[i].first < p[i].second)
	    res += p[i].first;
	else
	    res += p[i].second;
    }
    printf("%d\n",res);
}

int main(){
    read();
    return 0;
}
