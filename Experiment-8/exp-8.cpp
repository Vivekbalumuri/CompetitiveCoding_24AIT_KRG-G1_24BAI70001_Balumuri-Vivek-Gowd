#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = 0;
    // We check from the second element to the second-to-last element
    for (int i = 1; i < n - 1; i++) {
        // Check for the "disturbed" pattern: 1 0 1
        if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1) {
            // Greedy: Turn off the light at i + 1 to maximize the fix
            a[i + 1] = 0;
            k++;
        }
    }

    cout << k << endl;

    return 0;
}
