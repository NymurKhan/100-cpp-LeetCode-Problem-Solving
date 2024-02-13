#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    cout << "Are '" << s << "' and '" << t << "' anagrams? " << (solution.isAnagram(s, t) ? "Yes" : "No") << endl; // Output: Yes
    return 0;
}
