#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int needed = target - nums[i];
            if (mpp.find(needed) != mpp.end()) {
                return {mpp[needed], i};
            }
            mpp[num] = i;
        }
        return {-1, -1}; // No valid pair found (there is no pair which sum to target)
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Function call
    vector<int> result = sol.twoSum(nums, target);

    // Output the result
    if (result[0] != -1) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}


// Time Complexity:
// O(n), where n is the size of the array.

// You loop over all elements once, and each map.find() and map[] operation takes O(log n) since std::map is a Red-Black Tree.

// So technically it's O(n log n) in worst case.

// ✅ If you replace map<int, int> with unordered_map<int, int>, it becomes:

// Time Complexity: O(n) average case

// Because unordered_map operations (find, insert) are O(1) on average