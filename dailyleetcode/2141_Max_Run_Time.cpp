#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        using ll = long long;

        ll sum = 0;
        for (int b : batteries) {
            sum += b;
        }

        ll low = 0;
        ll high = sum / n; // maximum possible time

        auto canRun = [&](ll T) -> bool {
            ll total = 0;
            for (int b : batteries) {
                total += min<ll>(b, T);
                if (total >= (ll)n * T) return true; // early stop
            }
            return total >= (ll)n * T;
        };

        while (low < high) {
            ll mid = low + (high - low + 1) / 2; // upper mid
            if (canRun(mid)) {
                low = mid;       // mid is possible, try to increase
            } else {
                high = mid - 1;  // mid not possible, decrease
            }
        }

        return low;
    }
};
