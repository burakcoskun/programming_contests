#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int first_0_to_1 = -1;
    int last_0_to_1 = -1;
    int first_1_to_0 = -1;
    int last_1_to_0 = -1;
    for(int i = 0; i < n -1 ;++i) {
        if(s[i] == '0' && s[i+1] == '1') {
            if(first_0_to_1 == -1)
                first_0_to_1 = i;
            last_0_to_1 = i;
        }
        if(s[i] == '1' && s[i+1] == '0') {
            if(first_1_to_0 == -1)
                first_1_to_0 = i;
            last_1_to_0 = i;
        }
    }
    int res = 0;
    if(s[0] == '1') {
        first_0_to_1 = 0;
        res = 1;
    }
    for(int i = 0; i < n - 1; ++i){
        ++res;
        if(s[i] == '0' && s[i+1] == '1')
            ++res;
        if(s[i] == '1' && s[i+1] == '0')
            ++res;
    }
    ++res;
    if(first_0_to_1 < last_0_to_1)
        res -= 2;
    else if(first_1_to_0 < last_1_to_0)
        res -= 2;
    else if(n > 1 &&(first_0_to_1 != -1 && first_1_to_0 != -1) && (first_0_to_1 < n - 1 || first_1_to_0 < n - 1))
        res--;
    cout << res << endl;
  }
  return 0;
}
