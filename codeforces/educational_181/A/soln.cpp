#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    string res;
    int count_t = 0;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == 'T')
            ++count_t;
    }
    for(int i = 0; i < count_t ; ++i)
        res.push_back('T');
    for(int i = 0; i < s.size(); ++i)
        if(s[i] != 'T')
            res.push_back(s[i]);
    cout << res << endl;
  }
  return 0;
}
