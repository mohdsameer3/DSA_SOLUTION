#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string s, int open, int close, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(s);
            return;
        }
        if (open != 0) {
            string op1 = s;
            op1 += '(';
            solve(op1, open - 1, close, ans);
        }
        if (close > open) {
            string op2 = s;
            op2 += ')';
            solve(op2, open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, n, ans);
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;

    Solution sol;
    vector<string> result = sol.generateParenthesis(n);

    cout << "All combinations of well-formed parentheses are:\n";
    for (const string& str : result) {
        cout << str << '\n';
    }

    return 0;
}
