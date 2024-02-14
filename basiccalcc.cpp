#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int sign = 1;
        stack<pair<int, int>> st;
        
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                sum += num * sign;
                --i; // to adjust the index after the while loop
                sign = 1; // reset sign
            } else if (ch == '(') {
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            } else if (ch == ')') {
                auto [val_at_top, sign_at_top] = st.top();
                st.pop();
                sum = val_at_top + (sign_at_top * sum);
            } else if (ch == '-') {
                sign = -sign; // toggle sign
            }
        }
        
        return sum;
    }
};

int main() {
    Solution sol;
    string expression = "1 + 2 + 3 - (5 + 6)";
    int result = sol.calculate(expression);
    cout << "Result: " << result << endl; // Output should be -5
    return 0;
}
