#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    for(int i = n-1; i >= 0; --i)
      if(s[i] != s[n-1])
        ++res;
    cout << res << endl; 
  }
  return 0;
}
