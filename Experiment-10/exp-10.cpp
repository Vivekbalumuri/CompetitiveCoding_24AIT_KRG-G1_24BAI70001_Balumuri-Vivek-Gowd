#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Find the index of the first pile that is NOT 1
    int first_not_one = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) {
            first_not_one = i;
            break;
        }
    }

    if (first_not_one == -1) {
        // All piles are 1s, winner depends on parity of n
        if (n % 2 == 1) cout << "First" << endl;
        else cout << "Second" << endl;
    } else {
        // The player who reaches the first >1 pile wins.
        // If it's an even index (0, 2, 4...), the First player reaches it.
        // If it's an odd index (1, 3, 5...), the Second player reaches it.
        if (first_not_one % 2 == 0) cout << "First" << endl;
        else cout << "Second" << endl;
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
