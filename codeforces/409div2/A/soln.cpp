#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;


string s;

int how_many(string s1){
    int res = 0 ;
    for(int i = 0 ; i < s1.size() - 1 ;++i)
	if(s1[i]=='V' && s1[i+1] =='K')
	    res++;
    return res;
}
void read_input(){
    cin >> s;
    int res = how_many(s);
    for(int c = 0 ; c < s.size(); c++){
	char ch = s[c];

	s[c] = 'V';
	res = max(res,how_many(s));
	s[c] = 'K';
	res = max(res,how_many(s));
	s[c] = ch;
    }

    cout << res << endl;
}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
