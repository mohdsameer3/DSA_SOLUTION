#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Since the input array is sorted, we can use two pointers
    vector<int> twoSumSorted(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                // Found the pair
                return {left, right};
            } else if (sum < target) {
                // Need a larger sum, move left pointer
                left++;
            } else {
                // Need a smaller sum, move right pointer
                right--;
            }
        }

        // No valid pair found
        return {-1, -1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 4, 6, 10};
    int target = 8;

    vector<int> result = sol.twoSumSorted(nums, target);

    if (result[0] != -1) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
        cout << "Values: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}
