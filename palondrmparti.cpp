#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--]) return false;
        return true;
    }

    int fn(string s, int n, int ind) {
        if (ind == n) return -1;
        int mini = 1e9;
        for (int i = ind; i < n; i++) {
            if (isPalindrome(s, ind, i)) {
                int cut = 1 + fn(s, n, i + 1);
                mini = min(mini, cut);
            }
        }
        return mini;
    }

    int minCut(string s) {
        int n = s.size();
        return fn(s, n, 0);
    }
};

int main() {
    Solution sol;
    string s = "aab";
    int result = sol.minCut(s);
    cout << "Minimum number of cuts to make '" << s << "' a palindrome partition: " << result << endl;
    return 0;
}
