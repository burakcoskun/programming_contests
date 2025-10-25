#include <bits/stdc++.h>

using namespace std;

bool is_prime(int k){
  if(k < 2 )
    return false;
  for(int i = 2; i * i <= k; ++i)
    if(k % i == 0)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i = 0; i < 200000; ++i)
    if(is_prime(i))
      cout << i << endl;
  return 0;
}
