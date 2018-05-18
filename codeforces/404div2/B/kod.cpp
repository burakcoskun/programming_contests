#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int n,m;

int c_first_finish = 1000000001,c_last_start;
int m_last_start, m_first_finish = 1000000001;

int main(){

    scanf(" %d",&n);

    int a, b;

    for(int i = 0 ; i < n; ++i){
	scanf(" %d %d",&a ,&b);
	if( a > c_last_start)
	    c_last_start = a; 
	if(c_first_finish > b)
	    c_first_finish = b;
    }

    scanf(" %d",&m);
    for(int i = 0; i<m; ++i){
	scanf(" %d %d",&a,&b);
	if(a > m_last_start)
	    m_last_start = a;
	if(m_first_finish > b)
	    m_first_finish = b;
    }

    //printf("%d %d -- %d %d\n",c_first_finish,c_last_start,m_first_finish,m_last_start);

    int res = max(m_last_start-c_first_finish,c_last_start-m_first_finish);
    res = max(res,0);
    printf("%d\n",res);

    return 0;
}
