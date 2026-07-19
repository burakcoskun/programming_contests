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
    int n = s.size();
    int first_left = 0, last_right = 0;
    for(int i = 0; i < n && s[i] == '<'; ++i)
      ++first_left;
    for(int i = n - 1; i >= 0 && s[i] == '>'; --i)
      ++last_right;
    
    int ans;
    if(first_left + last_right + 1 >= n) {
      ans = max(first_left, last_right);
      if(first_left + last_right < n)
        ++ans;
    }
    else 
      ans = -1;

    cout << ans << endl;
  }
  return 0;
}
