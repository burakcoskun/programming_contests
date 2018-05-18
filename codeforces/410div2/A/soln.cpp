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

int is_palindrome(string p){
    for(int i = 0 ; i < p.size(); ++i)
	if(p[i] != p[p.size() - 1 - i])
	    return 0;
    return 1;
}

void read_input(){
    cin >> s;

    for(int i = 0 ; i < s.size() ; ++i)
	for(int j = 0 ; j < 26 ; ++j){
	    char ch = s[i];
	    if(j != s[i] - 'a'){
		s[i] = 'a'+j;
		if(is_palindrome(s)){
		    cout << "YES\n";
		    return ;
		}
	    }
	    s[i] = ch;
	}
    cout << "NO\n";

}

void calc(){
}

int main(){
    read_input();
    calc();
    return 0;
}
