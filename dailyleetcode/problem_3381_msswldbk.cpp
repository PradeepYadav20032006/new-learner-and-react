#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        using ll = long long;
        const ll INF = (ll)4e18;

        int n = nums.size();
        vector<ll> minPrefix(k, INF); 

        ll prefix = 0;
        ll ans = -INF;
        minPrefix[k - 1] = 0;

        for (int i = 0; i < n; ++i) {
            prefix += nums[i];

            int r = i % k;

            ans = max(ans, prefix - minPrefix[r]);
            minPrefix[r] = min(minPrefix[r], prefix);
        }

        return ans;
    }
};
