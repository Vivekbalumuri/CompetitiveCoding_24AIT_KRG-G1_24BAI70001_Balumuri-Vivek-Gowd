#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << -1 << endl;
        return;
    }

    vector<int> res;
    // First, collect all odd numbers
    for (int i = 1; i <= n * n; i += 2) {
        res.push_back(i);
    }
    // Then, collect all even numbers
    for (int i = 2; i <= n * n; i += 2) {
        res.push_back(i);
    }

    // Print as an n x n matrix
    for (int i = 0; i < n * n; i++) {
        cout << res[i] << ( (i + 1) % n == 0 ? "\n" : " " );
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
