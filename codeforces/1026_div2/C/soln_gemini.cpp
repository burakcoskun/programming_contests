#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> d_initial(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> d_initial[i];
    }

    std::vector<long long> l_obs(n), r_obs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> l_obs[i] >> r_obs[i];
    }

    std::vector<long long> min_h(n + 1);
    std::vector<long long> max_h(n + 1);

    min_h[0] = 0;
    max_h[0] = 0;

    bool possible = true;
    for (int i = 0; i < n; ++i) { // Current step uses d_initial[i], l_obs[i], r_obs[i] to determine h[i+1]
        long long prev_min_val = min_h[i];
        long long prev_max_val = max_h[i];

        long long potential_min_h_curr_step, potential_max_h_curr_step;

        if (d_initial[i] == 0) {
            potential_min_h_curr_step = prev_min_val + 0;
            potential_max_h_curr_step = prev_max_val + 0;
        } else if (d_initial[i] == 1) {
            potential_min_h_curr_step = prev_min_val + 1;
            potential_max_h_curr_step = prev_max_val + 1;
        } else { // d_initial[i] == -1
            potential_min_h_curr_step = prev_min_val + 0; // Min height if we choose d=0
            potential_max_h_curr_step = prev_max_val + 1; // Max height if we choose d=1
        }

        min_h[i + 1] = std::max(potential_min_h_curr_step, l_obs[i]);
        max_h[i + 1] = std::min(potential_max_h_curr_step, r_obs[i]);

        if (min_h[i + 1] > max_h[i + 1]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        std::cout << -1 << std::endl;
        return;
    }

    std::vector<int> ans_d(n);
    long long actual_h_at_k = max_h[n]; // Start with max possible height at the last obstacle (h_n)

    // Iterate backwards from k=n down to 1 (to determine d_k)
    // In 0-indexed arrays, this is for d_initial[i] where i goes from n-1 down to 0
    // actual_h_at_k is h_{i+1}
    // We need to determine d[i]
    // The previous state height is h_i, which has range [min_h[i], max_h[i]]
    for (int i = n - 1; i >= 0; --i) { 
        if (d_initial[i] == 0) {
            ans_d[i] = 0;
        } else if (d_initial[i] == 1) {
            ans_d[i] = 1;
        } else { // d_initial[i] == -1
            // Choose d_ans[i] such that h_i = actual_h_at_k - d_ans[i] is maximized
            // while h_i <= max_h[i]. This means d_ans[i] should be minimized.
            // d_ans[i] >= actual_h_at_k - max_h[i]
            // d_ans[i] >= 0
            // So, d_ans[i] = std::max(0LL, actual_h_at_k - max_h[i])
            ans_d[i] = std::max(0LL, actual_h_at_k - max_h[i]);
        }
        actual_h_at_k -= ans_d[i]; // This becomes h_i for the next iteration (effectively)
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans_d[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}