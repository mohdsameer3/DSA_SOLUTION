#include <iostream>
#include <vector>
using namespace std;

// Function to find maximum element in the array  
// Time complexity  = O(n) where is the size of the array
int findMax( vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findMax(arr);
    cout << "Maximum element in the array is: " << result << endl;

    return 0;
}
