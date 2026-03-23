#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for(int p : piles)
            high = max(high, p);

        while(low < high) {
            int mid = (low + high) / 2;
            int hours = 0;

            for(int p : piles)
                hours += ceil((double)p / mid);

            if(hours <= h)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};
