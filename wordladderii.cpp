#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ds(wordList.begin(), wordList.end());      
        int c = 1;
        queue<string> q;
        q.push(beginWord);
        unordered_map<string, int> m;
        m[beginWord] = 1;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string s = q.front();
                q.pop();
                if (s == endWord)
                    return c;
                for (int i = 0; i < s.length(); i++) {
                    char t = s[i];
                    for (int j = 0; j < 26; j++) {
                        s[i] = j + 97;
                        if (!m[s] && ds.find(s) != ds.end()) {
                            q.push(s);
                            m[s] = 1;
                        }
                    }
                    s[i] = t;
                }
            }
            c++;
        }
        return 0;
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Length of ladder from '" << beginWord << "' to '" << endWord << "': " << result << endl;
    return 0;
}
