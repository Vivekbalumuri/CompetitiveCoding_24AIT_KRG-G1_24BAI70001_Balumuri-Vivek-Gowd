#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<pair<int, int>> edges(n - 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
        degree[edges[i].first]++;
        degree[edges[i].second]++;
    }

    // Find a node with degree >= 3
    int special_node = -1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] >= 3) {
            special_node = i;
            break;
        }
    }

    vector<int> result(n - 1, -1);
    int current_low = 0;
    int current_high = 3;

    if (special_node != -1) {
        // Assign 0, 1, 2 to edges connected to the special node
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if ((edges[i].first == special_node || edges[i].second == special_node) && count < 3) {
                result[i] = count++;
            }
        }
        // Assign the remaining numbers (3 to n-2) to other edges
        for (int i = 0; i < n - 1; i++) {
            if (result[i] == -1) {
                result[i] = current_high++;
            }
        }
    } else {
        // If it's a line, any order works (0 to n-2)
        for (int i = 0; i < n - 1; i++) {
            result[i] = i;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
