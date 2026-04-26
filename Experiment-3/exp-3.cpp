#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long t;
    if (!(cin >> n >> t)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_books = 0;
    int current_sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        current_sum += a[right];

        // If the current sum exceeds time t, shrink the window from the left
        while (current_sum > t) {
            current_sum -= a[left];
            left++;
        }

        // The number of books in the current valid window is (right - left + 1)
        max_books = max(max_books, right - left + 1);
    }

    cout << max_books << endl;

    return 0;
}
