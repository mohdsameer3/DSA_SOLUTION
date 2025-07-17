#include <bits/stdc++.h>
using namespace std;

class LongestModuloSubsequence {
public:
    int findMaximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int maxLength = 0;
        for (int num : nums) {
            int remainder = num % k;
            for (int prev = 0; prev < k; ++prev) {
                dp[prev][remainder] = dp[remainder][prev] + 1;
                maxLength = max(maxLength, dp[prev][remainder]);
            }
        }
        return maxLength;
    }
};

int main() {
    int n, k;
    cout << "Enter the size of the array and the value of k: ";
    cin >> n >> k;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    LongestModuloSubsequence solver;
    int result = solver.findMaximumLength(nums, k);
    cout << "Maximum subsequence length: " << result << endl;

    return 0;
}
