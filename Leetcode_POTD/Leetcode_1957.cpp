#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        if (n < 3) return s;

        string result = "";
        int count = 1;                  // To count consecutive characters
        char prevChar = s[0];          // First character
        result.push_back(prevChar);    // Always keep the first character

        for (int i = 1; i < n; ++i) {
            if (s[i] == prevChar) {
                count++;
            } else {
                prevChar = s[i];
                count = 1;
            }

            if (count < 3) {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = sol.makeFancyString(input);
    cout << "Fancy string: " << output << endl;

    return 0;
}
