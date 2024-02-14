#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev) {
        for (int i = 0; i < prev.size(); ++i) {
            prev[i] += " " + word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        if (m.count(s)) return m[s]; // Take from memory
        vector<string> result;
        if (dict.count(s)) { // A whole string is a word
            result.push_back(s);
        }
        for (int i = 1; i < s.size(); ++i) {
            string word = s.substr(i);
            if (dict.count(word)) {
                string rem = s.substr(0, i);
                vector<string> prev = combine(word, wordBreak(rem, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        m[s] = result; // Memorize
        return result;
    }
};

int main() {
    Solution sol;
    string s = "catsanddog";
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> result = sol.wordBreak(s, dict);
    cout << "Word break combinations for '" << s << "':" << endl;
    for (const auto& word : result) {
        cout << word << endl;
    }
    return 0;
}
