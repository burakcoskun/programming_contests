#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<string> dict;
int mark[500005];
int res;

void read_input(){
    cin >> n;
    string s;
    for(int i = 0 ; i < n ; ++i){
	cin >> s;
	dict.push_back(s);
    }
}

void calc(){
    int m_len = dict[n-1].length();
    for(int k = n-1 ; k ; ){
    	for(int i = 1; i < dict[k].length() ;++i){
	    char m_char = dict[k][i];
	    int j =  k -1;
		if(mark[j]!=k && dict[j].length() > i  && dict[j][i] > m_char){
		    res += dict[j].length() - (i-1);
		    dict[j].erase(i,string::npos);
		    continue;
		}
		else if(dict[j].length() > i && dict[j][i] < m_char)
		    mark[j] = k;
		if(dict[j].length() > i+1 && i == dict[k].length()-1 && mark[j]!=k){
		    res += dict[j].length() - (i);
		    dict[j].erase(i+1,string::npos);
		}
	}
	k--;
	while(k > 0 && dict[k].length() <= m_len)
	    k--;
	m_len = dict[k].length();
    }
}

void print(){
    for(int i = 0 ; i < n; ++i)
	cout << dict[i] << "\n" ;
}

int main(){
    read_input();
    calc();
    print();
    return 0;
}
