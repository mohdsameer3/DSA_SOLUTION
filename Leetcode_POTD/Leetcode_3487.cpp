#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            int max_elem = *max_element(nums.begin(), nums.end());
            return max_elem;
        } else {
            int sum = 0;
            set<int> st;
            for (int i = 0; i < n; i++) {
                if (st.find(nums[i]) == st.end() && nums[i] >= 0) {
                    sum += nums[i];
                    st.insert(nums[i]);
                }
            }
            return sum;
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums1 = {1, 2, 2, 3, -4, -5};
    vector<int> nums2 = {-5, -8, -1, -9}; // All negative
    vector<int> nums3 = {0, 0, 1, 2};     // Duplicates and zero

    cout << "Max sum of unique non-negative elements (nums1): " << sol.maxSum(nums1) << endl;
    cout << "Max element (all negative nums2): " << sol.maxSum(nums2) << endl;
    cout << "Max sum of unique non-negative elements (nums3): " << sol.maxSum(nums3) << endl;

    return 0;
}
