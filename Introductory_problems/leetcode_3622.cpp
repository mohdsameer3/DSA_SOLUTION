// <!-- ✅✅ ## Problem: Check Divisibility by Sum and Product of Digits ✅✅

// Given an integer `n`, return `true` if `n` is divisible by the sum **plus** the product of its digits, otherwise return `false`.

// ### Example:
// Input: `n = 132`  
// Digits: 1, 3, 2  
// Sum = 6  
// Product = 6  
// Sum + Product = 12  
// Check: `132 % 12 == 0` → ✅ Return `true`

// ### Constraints:
// - `1 <= n <= 10^9`


//code implementation 


#include <iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int pro = 1;

        while (temp > 0) {
            int digit = temp % 10;
            sum += digit;
            pro *= digit;
            temp /= 10;
        }

        int div = sum + pro;
        return (n % div == 0);
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (sol.checkDivisibility(n)) {
        cout << n << " is divisible by the sum + product of its digits.\n";
    } else {
        cout << n << " is NOT divisible by the sum + product of its digits.\n";
    }

    return 0;
}



// complextiy 
// Time:  O(log n)
// Space: O(1)