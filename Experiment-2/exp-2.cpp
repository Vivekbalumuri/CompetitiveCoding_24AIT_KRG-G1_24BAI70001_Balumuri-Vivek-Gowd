#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    int initial_ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) initial_ones++;
    }

    int max_ones = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int current_ones = initial_ones;
            for (int k = i; k <= j; k++) {
                if (a[k] == 1) {
                    current_ones--;
                } else {
                    current_ones++;
                }
            }
            max_ones = max(max_ones, current_ones);
        }
    }

    cout << max_ones << endl;

    return 0;
}
