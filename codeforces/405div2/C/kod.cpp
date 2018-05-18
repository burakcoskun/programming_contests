#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n,k;
vector<string> dis;
vector<string> res;
string nextName = "A";

string getNext(){
    if(nextName.size() == 1 && nextName[0] != 'Z')
	nextName[0]++;
    else if(nextName.size() == 2)
	nextName[1]++;
    else
	nextName+="a";
    return nextName;
}

void read_input(){
    scanf(" %d %d",&n,&k);
    nextName[0]='A'-1;
    res.resize(n);
    string s;
    for(int i = 0; i<= n-k ; ++i){
	cin >> s;
	dis.push_back(s);
	if(s == "YES"){
	    for(int j=i;j<i+k;++j)
	    	if(res[j] =="")
	    		res[j] = getNext();
	}
    }
}

void calc(){
    for(int i = 0; i <= n-k; ++i){
	if(dis[i] == "NO"){
	    string s;
	    for(int j=i; j < i+k;++j)
		if(res[j].size() > 0){
		    s = res[j];
		    break;
		}
	    for(int j=i;j<i+k;++j)
		if(res[j] =="")
		    res[j] = s;
	}
    }
}

int main(){
    read_input();
    calc();
    for(int i =0 ; i < n-1; ++i)
	cout << res[i] << " ";
    cout << res[n-1];
    return 0;
}
