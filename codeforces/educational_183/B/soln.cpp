#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, k;

    cin >> n >> k;
    string s;
    cin >> s;

    int left = 0, right = 0, both = 0;
    for(int i = 0; i < k; ++i) {
      if(s[i] == '0') {
        ++left;
      }
      else if(s[i] == '1') {
        ++right;
      }
      else {
        ++both;
      }
    }
    for(int i = 0; i < n; ++i) {
      if(i+1 <= left)
        cout << '-';
      else if(n-i <= right)
        cout << '-';
      else if(i-left + (n-(i+1)-right) < both)
        cout << '-';
      else { // it might stay on the deck
        if(i +1 <= left + both)
          cout << '?';
        else if (n-i <= right + both)
          cout << '?';
        else cout << '+';
      }
    }
    cout << endl;
  }
  return 0;
}
