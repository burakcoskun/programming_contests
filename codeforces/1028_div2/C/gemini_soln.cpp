#include <iostream>
#include <vector>
#include <algorithm>

// A structure to hold a point's data: coordinates and original index.
struct Point {
    int x, y;
    int id;
};

// Comparison function for sorting points primarily by x-coordinate.
// This is used for the initial partition.
bool compareByX(const Point& a, const Point& b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    return a.y < b.y; // Tie-breaker
}

// Comparison function for sorting points by y-coordinate.
// This is used for the matching step within each partition.
bool compareByY(const Point& a, const Point& b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x; // Tie-breaker
}

void solve() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].x >> points[i].y;
        points[i].id = i + 1; // Store the original 1-based index
    }

    // --- Step 1: Partition by X-coordinate ---
    // Sort all points by 'x' to create the optimal partition that
    // maximizes the sum of x-distances.
    std::sort(points.begin(), points.end(), compareByX);

    // Create the two groups based on the x-partition.
    std::vector<Point> left_half;
    std::vector<Point> right_half;
    int half_size = n / 2;

    for (int i = 0; i < half_size; ++i) {
        left_half.push_back(points[i]);
    }
    for (int i = 0; i < half_size; ++i) {
        right_half.push_back(points[i + half_size]);
    }

    // --- Step 2: Sort for Y-Matching ---
    // To maximize the y-distances for this partition, we sort each
    // half by its y-coordinate.
    std::sort(left_half.begin(), left_half.end(), compareByY);
    std::sort(right_half.begin(), right_half.end(), compareByY);
    
    // --- Step 3: Optimal Pairing ---
    // Pair the i-th smallest 'y' from the left half with the i-th
    // largest 'y' from the right half. This is achieved by pairing
    // left_half[i] with the corresponding element from the *reversed*
    // right_half.
    for (int i = 0; i < half_size; ++i) {
        std::cout << left_half[i].id << " " << right_half[i].id << "\n";
    }
}

int main() {
    // Use fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}