#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        const string_view sv_t(t), sv_s(s);
        for (int i = 0; i < s.length(); ++i)
            if (sv_t.substr(i) == sv_s.substr(0, s.length() - i))
                return t.substr(0, i) + s;
        return t + s;
    }
};

int main() {
    Solution sol;
    string input = "abcd";
    string result = sol.shortestPalindrome(input);
    cout << "Shortest palindrome of \"" << input << "\" is: " << result << endl;
    return 0;
}
