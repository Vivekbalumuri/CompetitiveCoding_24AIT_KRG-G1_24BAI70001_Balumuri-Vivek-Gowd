#include <iostream>
#include <numeric> // For std::gcd or std::lcm (C++17)
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long MOD = 1e9 + 7;
        
        // Calculate LCM: (a * b) / GCD(a, b)
        // Note: Use long long to prevent overflow during (a * b)
        long long L = (1LL * a * b) / gcd(a, b);
        
        // Binary Search range
        long long low = min(a, b);
        long long high = 1LL * n * min(a, b);
        long long ans = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            // Inclusion-Exclusion: numbers divisible by a OR b
            long long count = (mid / a) + (mid / b) - (mid / L);
            
            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans % MOD;
    }

private:
    
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
