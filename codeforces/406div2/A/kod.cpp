#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int a,b,c,d;

void read_input(){
    scanf(" %d %d %d %d",&a,&b,&c,&d);

    if(b == d)
	printf("%d\n",d);
    else{
	int res = -1;
	for(int k1 = 0; k1 <= 2000; ++k1)
	    for(int k2 = 0; k2 <=2000; ++k2)
		if(b + a * k1 == d + c*k2)
		    if(b+a*k1 < res || res ==-1)
			res = b+a*k1;
	printf("%d\n",res);
    }

}

int main(){
    read_input();
    return 0;
}
