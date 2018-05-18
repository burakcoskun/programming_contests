#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int A,B;

void read_input(){
    scanf(" %d %d",&A,&B);
    int i = 0 ;
    while(A <= B){
	A *= 3;
	B *= 2;
	++i;
    }
    printf("%d\n",i);
}

int main(){
    read_input();
    return 0;
}
