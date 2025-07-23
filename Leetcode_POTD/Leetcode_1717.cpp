#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// Paste your Solution class here
class Solution {
public:
    typedef long long ll;
    int maximumGain(string s, int x, int y) {
        stack<char> st1;
        ll cnt1 = 0, cnt2 = 0;
        for (char ch : s) {
            if (st1.empty())
                st1.push(ch);
            else {
                if (!st1.empty() && st1.top() == 'a' && ch == 'b') {
                    cnt1++;
                    st1.pop();
                } else
                    st1.push(ch);
            }
        }
        stack<char> st2;
        for (char ch : s) {
            if (st2.empty())
                st2.push(ch);
            else {
                if (!st2.empty() && st2.top() == 'b' && ch == 'a') {
                    cnt2++;
                    st2.pop();
                } else
                    st2.push(ch);
            }
        }
        if ((cnt1 * x) > (cnt2 * y)) {
            string temp = "";
            while (!st1.empty()) {
                temp.push_back(st1.top());
                st1.pop();
            }
            reverse(temp.begin(), temp.end());
            int Newcnt1 = 0;
            for (char ch : temp) {
                if (st1.empty())
                    st1.push(ch);
                else {
                    if (!st1.empty() && st1.top() == 'b' && ch == 'a') {
                        Newcnt1++;
                        st1.pop();
                    } else
                        st1.push(ch);
                }
            }
            return (cnt1 * x) + (Newcnt1 * y);
        } else {
            string temp = "";
            while (!st2.empty()) {
                temp.push_back(st2.top());
                st2.pop();
            }
            reverse(temp.begin(), temp.end());
            int Newcnt1 = 0;
            for (char ch : temp) {
                if (st2.empty())
                    st2.push(ch);
                else {
                    if (!st2.empty() && st2.top() == 'a' && ch == 'b') {
                        Newcnt1++;
                        st2.pop();
                    } else
                        st2.push(ch);
                }
            }
            return (Newcnt1 * x) + (cnt2 * y);
        }
    }
};

int main() {
    Solution sol;

    string s = "cdbcbbaaabab";
    int x = 4, y = 5;

    int result = sol.maximumGain(s, x, y);
    cout << "Maximum score: " << result << endl;

    return 0;
}
