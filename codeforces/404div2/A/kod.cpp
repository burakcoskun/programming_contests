#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

int n,res;

int main(){

    string s;
    scanf(" %d",&n);
    for(int i=0;i<n;++i){
	cin >> s;
	if(s.compare("Tetrahedron") == 0 )
	    res += 4;
	else if(s.compare("Cube") == 0)
	    res += 6;
	else if(s.compare("Octahedron") == 0)
	    res += 8;
	else if(s.compare("Dodecahedron") == 0)
	    res += 12;
	else if(s.compare("Icosahedron") == 0)
	    res += 20;
    }
    printf("%d\n",res);
    return 0;
}
