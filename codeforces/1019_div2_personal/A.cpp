#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        vector<int> a(105, 0);
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int num;
            cin >> num;
            a[num] = 1;
        }
        int res = 0;
        for (int i = 0; i <= n; ++i)
        {
            if (a[i])
                res++;
        }
        cout << res << endl;
        t--;
    }
    return 0;
}
