#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    // Include current element
    current.push_back(nums[index]);
    generateSubsets(index + 1, nums, current, result);

    // Exclude current element
    current.pop_back();
    generateSubsets(index + 1, nums, current, result);
}

int main() {
    vector<int> nums = {1, 2, 3};  // You can change this input
    vector<vector<int>> result;
    vector<int> current;

    generateSubsets(0, nums, current, result);

    // Print all subsets
    cout << "All subsets:\n";
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }

    return 0;
}

//  Time & Space Complexity
// Time Complexity: O(2^n) — Each element can either be included or not.

// Space Complexity: O(2^n * n) — Total subsets × max size of subset.